#pragma once

#include "FA2PP.h"

class NOVTABLE CUpdateProgress : public ppmfc::CDialog
{
public:
	CUpdateProgress() = default;

	//member properties
	int Unknown_92;
	CProgressCtrl ProgressBar;
	ppmfc::CString CString_Title;
	ppmfc::CString CString_Buffer;

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D3BE0);
	}
};