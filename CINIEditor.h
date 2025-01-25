#pragma once

#include "FA2PP.h"

class NOVTABLE CINIEditor : public ppmfc::CDialog
{
public:
	CINIEditor() = default;

	//member properties
	ppmfc::CEdit				CETValue; // 92
	ppmfc::CListBox		CLBKeys; // 152
	CButton			CBNInsertAnotherINIFileContent; // 212
	CButton			CBNDeleteSection; // 272
	CButton			CBNDeleteKey; // 332
	CButton			CBNAddSection; // 392
	CButton			CBNAddKey; // 452
	ppmfc::CComboBox	CCBSectionList; // 512


	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x40A440); }

	void OnClickImportINI() 
		{ JMP_THIS(0x40B740); }
};