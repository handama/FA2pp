#pragma once

#include <MFC/ppmfc_cstring.h>

#include <cstring>

enum class ObjectType
{
    Infantry = 0,
    Structure = 1,
    Aircraft = 2,
    Unit = 3,
    Overlay = 4,
    Celltag = 5,
    Waypoints = 6
};

class CInfantryData
{
public:
    CInfantryData& operator=(const CInfantryData& another)
    {
        House = another.House;
        TypeID = another.TypeID;
        Health = another.Health;
        Y = another.Y;
        X = another.X;
        SubCell = another.SubCell;
        Status = another.Status;
        Facing = another.Facing;
        Tag = another.Tag;
        VeterancyPercentage = another.VeterancyPercentage;
        Group = another.Group;
        IsAboveGround = another.IsAboveGround;
        AutoNORecruitType = another.AutoNORecruitType;
        AutoYESRecruitType = another.AutoYESRecruitType;
        Flag = another.Flag;
        return *this;
    };

    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString SubCell;
    ppmfc::CString Status;
    ppmfc::CString Facing;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    bool Flag : 1;
};

class CBuildingData
{
public:
    CBuildingData& operator=(const CBuildingData& another)
    {
        House = another.House;
        TypeID = another.TypeID;
        Health = another.Health;
        Y = another.Y;
        X = another.X;
        Facing = another.Facing;
        Tag = another.Tag;
        AISellable = another.AISellable;
        AIRebuildable = another.AIRebuildable;
        PoweredOn = another.PoweredOn;
        Upgrades = another.Upgrades;
        SpotLight = another.SpotLight;
        Upgrade1 = another.Upgrade1;
        Upgrade2 = another.Upgrade2;
        Upgrade3 = another.Upgrade3;
        AIRepairable = another.AIRepairable;
        Nominal = another.Nominal;
        Flag = another.Flag;
        return *this;
    };

    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString Facing;
    ppmfc::CString Tag;
    ppmfc::CString AISellable;
    ppmfc::CString AIRebuildable;
    ppmfc::CString PoweredOn;
    ppmfc::CString Upgrades;
    ppmfc::CString SpotLight;
    ppmfc::CString Upgrade1;
    ppmfc::CString Upgrade2;
    ppmfc::CString Upgrade3;
    ppmfc::CString AIRepairable;
    ppmfc::CString Nominal;
    bool Flag : 1;
};

class CUnitData
{
public:
    CUnitData& operator=(const CUnitData& another)
    {
        House = another.House;
        TypeID = another.TypeID;
        Health = another.Health;
        Y = another.Y;
        X = another.X;
        Facing = another.Facing;
        Status = another.Status;
        Tag = another.Tag;
        VeterancyPercentage = another.VeterancyPercentage;
        Group = another.Group;
        IsAboveGround = another.IsAboveGround;
        FollowsIndex = another.FollowsIndex;
        AutoNORecruitType = another.AutoNORecruitType;
        AutoYESRecruitType = another.AutoYESRecruitType;
        Flag = another.Flag;
        return *this;
    };

    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString Facing;
    ppmfc::CString Status;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString FollowsIndex;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    bool Flag : 1;
};

class CAircraftData
{
public:
    CAircraftData& operator=(const CAircraftData& another)
    {
        House = another.House;
        TypeID = another.TypeID;
        Health = another.Health;
        Y = another.Y;
        X = another.X;
        Facing = another.Facing;
        Status = another.Status;
        Tag = another.Tag;
        VeterancyPercentage = another.VeterancyPercentage;
        Group = another.Group;
        AutoNORecruitType = another.AutoNORecruitType;
        AutoYESRecruitType = another.AutoYESRecruitType;
        Flag = another.Flag;
        return *this;
    };

    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString Facing;
    ppmfc::CString Status;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    bool Flag : 1;
};

class CTerrainData
{
public:
    CTerrainData& operator=(const CTerrainData& another)
    {
        TypeID = another.TypeID;
        Y = another.Y;
        X = another.X;
        Flag = another.Flag;
        return *this;
    };

    ppmfc::CString TypeID;
    int Y;
    int X;
    bool Flag : 1;
};

class CSmudgeData
{
public:
    CSmudgeData& operator=(const CSmudgeData& another)
    {
        TypeID = another.TypeID;
        Y = another.Y;
        X = another.X;
        Flag = another.Flag;
        return *this;
    };

    ppmfc::CString TypeID;
    int Y;
    int X;
    bool Flag : 1;
};

static_assert(sizeof(CInfantryData) == 0x3C);
static_assert(sizeof(CBuildingData) == 0x48);
static_assert(sizeof(CUnitData) == 0x3C);
static_assert(sizeof(CAircraftData) == 0x34);
static_assert(sizeof(CTerrainData) == 0x10);
static_assert(sizeof(CSmudgeData) == 0x10);
