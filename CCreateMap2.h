#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap2 : public ppmfc::CDialog
{
public:
	CCreateMap2() = default;

	//member properties
	BOOL		BOOL_CompletelyNew; // 92
	BOOL		BOOL_EnableGlobalAITriggers; // 96

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D2D70); }
};