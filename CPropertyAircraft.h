#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyAircraft : public ppmfc::CDialog
{
public:
	//member properties
	ppmfc::CString			CString_HealthPoint; // ;/ Fill 92 - 96
	CSliderCtrl		CSCStrength;// 96
	ppmfc::CString			CString_Direction; // 156
	ppmfc::CString			CString_House; // 160
	ppmfc::CString			CString_VeteranLevel; // 164
	ppmfc::CString			CString_Group; // 168
	ppmfc::CString			CString_AutoCreateNoRecruitable; // 172
	ppmfc::CString			CString_AutoCreateYesRecruitable; // 176
	ppmfc::CString			CString_Status; // 180
	ppmfc::CString			CString_Tag;  // 184

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x401250); }

	CPropertyAircraft(ppmfc::CWnd* pParent) { JMP_THIS(0x401000); }

	void Translate() { JMP_THIS(0x401660); }

private:
	CPropertyAircraft(noinit_t) {}
};