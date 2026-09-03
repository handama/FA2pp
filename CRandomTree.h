#pragma once

#include "FA2PP.h"
#include <Structures/FAVector.h>

class NOVTABLE CRandomTree : public ppmfc::CDialog
{
public:
	static constexpr reference<FAVector<ppmfc::CString>, 0x72A860> const RandomTrees{};

	CRandomTree()	
	{
		JMP_THIS(0x4D3FC0);
	}
	~CRandomTree()	
	{
		JMP_THIS(0x4D4080);
	}
	void OnBNToUsedClicked()
	{
		JMP_THIS(0x4D48B0);
	}
	void OnBNToAvailableClicked()
	{
		JMP_THIS(0x4D4960);
	}
	void OnLBAvailableSelectChanged()
	{
		JMP_THIS(0x4D4CB0);
	}
	void OnLBAvailableDoubleClicked()
	{
		JMP_THIS(0x4D4D80);
	}
	void OnLBUsedSelectChanged()
	{
		JMP_THIS(0x4D4E30);
	}
	void OnLBUsedDoubleClicked()
	{
		JMP_THIS(0x4D4F00);
	}
	void OnPaint()
	{
		JMP_THIS(0x4D4FB0);
	}
	//member properties
	char	CBNPreviewImage[60]; // CButton 92
	char	CLBUsed[60]; // ppmfc::CListBox 152
	char	CLBAvailable[60]; // ppmfc::CListBox 212
	ppmfc::CString		CString_Terrain; // 272

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D4100); }
};