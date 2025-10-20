#pragma once

#include "FA2PP.h"

class NOVTABLE CUpdateProgress : public ppmfc::CDialog
{
public:
	CUpdateProgress() = default;

	CUpdateProgress(ppmfc::CString lpDescription, ppmfc::CWnd* pParent)
		{ JMP_THIS(0x4D3A80); }

	~CUpdateProgress()
		{ JMP_THIS(0x4D3B70); }

	//member properties
	BOOL m_bCancel;
	CProgressCtrl ProgressBar;
	ppmfc::CString CString_Title;
	ppmfc::CString CString_Buffer;

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D3BE0); }
};