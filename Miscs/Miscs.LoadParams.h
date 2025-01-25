#pragma once

#include "../FA2PP.h"


namespace Miscs::LoadParams
{
    static void __cdecl LoadToCombobox(ppmfc::CComboBox* pComboBox, int nParamCode) {
        JMP_STD(0x43CE50);
    }

    static void __cdecl BuildingTypes(ppmfc::CComboBox* pComboBox, bool bDisplayAsName) {
        JMP_STD(0x43ED50);
    }

    static void __cdecl InfantryTypes(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x43F2C0);
    }

    static void __cdecl VehicleTypes(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x63F760);
    }

    static void __cdecl AircraftTypes(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x43FC00);
    }

    static void __cdecl TechnoTypes(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x4400A0);
    }

    static void __cdecl LocalVariables(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x441140);
    }

    static void __cdecl GlobalVariables(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x441530);
    }

    static void __cdecl TutorialTexts(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x441910);
    }

    static void __cdecl Triggers(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x441A40);
    }

    static void __cdecl YesNo(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x441E00);
    }

    static void __cdecl Sounds(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x441F20);
    }

    static void __cdecl Themes(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x442240);
    }

    static void __cdecl Speeches(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x442740);
    }

    static void __cdecl SuperWeaponTypes(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x442A60);
    }

    static void __cdecl Animations(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x442E50);
    }

    static void __cdecl Particles(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x443240);
    }

    static void __cdecl Movies(ppmfc::CComboBox* pComboBox, bool arg4, bool a3) {
        JMP_STD(0x443630);
    }

    static void __cdecl Tags(ppmfc::CComboBox* pComboBox, bool bHasNone) {
        JMP_STD(0x443F70);
    }

    static void __cdecl Houses(ppmfc::CComboBox* pComboBox, bool bDisplayIndex, bool bUseCountry, bool bMultiplayer) {
        JMP_STD(0x4448F0);
    }

    static void __cdecl TeamTypes(ppmfc::CComboBox* pComboBox, bool bLeaveNone) {
        JMP_STD(0x445B30);
    }

    static void __cdecl Waypoints(ppmfc::CComboBox* pComboBox) {
        JMP_STD(0x446070);
    }
};