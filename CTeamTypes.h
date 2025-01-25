#pragma once

#include "FA2PP.h"

class NOVTABLE CTeamTypes : public ppmfc::CDialog
{
public:
	CTeamTypes() = default;

	//member properties
	ppmfc::CStatic		CSTMindControlDecision; // 92
	ppmfc::CComboBox	CCBTeamList; // 152
	BOOL		BOOL_Aggressive; // 212
	BOOL		BOOL_Annoyance; // 216
	BOOL		BOOL_AreTeamMembersRecruitable; // 220
	BOOL		BOOL_Autocreate; // 224
	BOOL		BOOL_AvoidThreats; // 228
	BOOL		BOOL_Droppod; // 232 CargoPlane
	BOOL		BOOL_Full; // 236
	ppmfc::CString		CString_Group; // 240
	BOOL		BOOL_GuardSlower; // 244
	ppmfc::CString		CString_House; // 248 Country infact
	BOOL		BOOL_IonImmune; // 252 Useless
	BOOL		BOOL_IsBaseDefense; // 256
	BOOL		BOOL_Loadable; // 260
	BOOL		BOOL_LooseRecruit; // 264
	ppmfc::CString		CString_Max; // 268
	ppmfc::CString		CString_Name; // 272
	BOOL		BOOL_OnlyTargetHouseEnemy; // 276
	BOOL		BOOL_OnTransOnly; // 280
	BOOL		BOOL_Prebuild; // 284
	ppmfc::CString		CString_Priority; // 288
	BOOL		BOOL_Recruiter; // 292;
	BOOL		BOOL_Reinforce; // 296
	ppmfc::CString		CString_Script; // 300
	BOOL		BOOL_Suicide; // 304
	ppmfc::CString		CString_TaskForce; // 308
	ppmfc::CString		CString_TechLevel; // 312
	BOOL		BOOL_TransportsReturnOnUnload; // 316
	ppmfc::CString		CString_Waypoint; // 320
	BOOL		BOOL_Whiner; // 324
	ppmfc::CString		CString_VeteranLevel; // 328
	ppmfc::CString		CString_Tag; // 332
	ppmfc::CString		CString_TransportWaypoint; // 336
	ppmfc::CString		CString_MindControlDecision; // 340


	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x5971EC); }

	void OnBNNewTeamClicked()
	{
		JMP_THIS(0x4EEA50);
	}
	void OnCBCurrentTeamSelectedChanged()
	{
		JMP_THIS(0x4E7900);
	}
	void OnCBCurrentTaskForceSelectedChanged()
	{
		JMP_THIS(0x4EB760);
	}
	
	void OnCBCurrentScriptSelectedChanged()
	{
		JMP_THIS(0x4EB4D0);
	}

};