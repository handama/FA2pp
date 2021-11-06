#pragma once

#include "FA2PP.h"
#include "Structures/FAMap.h"

#include <ddraw.h>

class Palette;

enum class ImageDataFlag : unsigned int
{
    SurfaceData = 0,
    SHP = 1,
    VXL = 2
};

class NOVTABLE ImageDataClass
{
public:
    ImageDataClass() { JMP_THIS(0x475380) }; 
    
    void Initialize() { JMP_THIS(0x475380); } // probably ctor
    void Set(ImageDataClass* another) { JMP_THIS(0x4DE4F0); }
    void Clear() { JMP_THIS(0x4DE510); }

    union
    {
        unsigned char* pImageBuffer; // draw from here, size = FullWidth*FullHeight
        LPDIRECTDRAWSURFACE7 lpSurface; // Only available for flag = 0, if this is used, only ValidWidth and ValidHeight are set
    };

    struct ValidRangeData
    {
        short First;
        short Last;
    } *pPixelValidRanges;
    // size = FullHeight, stores the valid pixel from where to begin and end for each row
    // If it's an invalid row, then first = FullWidth - 1, second = 0 

    Palette* pPalette;
    short ValidX; // negative value for vxl, dunno why
    short ValidY; // negative value for vxl, dunno why
    short ValidWidth; // same as full for vxl, dunno why
    short ValidHeight; // same as full for vxl, dunno why
    short FullWidth;
    short FullHeight;
    ImageDataFlag Flag;
    bool IsOverlay; // Only OVRLXX_XX will set this true
};

struct BuildingData
{
    static constexpr reference<BuildingData, 0x627930, 3840> const Array{};

    ImageDataClass Facings[8];
    int FacingCount;
    unsigned __int8 Foundation_Width;
    unsigned __int8 Foundation_Height;
    int Unknown_108;
    int Unknown_10C;
    int Unknown_110;
};

struct OverlayData
{
    static constexpr reference<OverlayData, 0x5D8CF4, 255> const Array{};
    static constexpr reference<OverlayData*, 0x5E7C04> const LastOverlayData{};

    ImageDataClass* Frames[60];
};

using ImageDataMap = FAMap<ppmfc::CString, ImageDataClass, 0x5E7C18, 0>;
using SomeDataMap = FAMap<ppmfc::CString, bool, 0x5D8CD0, 0>;

class ImageDataMapHelper
{
private:
    ImageDataClass* GetImageDataFromMap(ppmfc::CString* ppName) { JMP_THIS(0x4768D0); }
public:
    static bool IsImageLoaded(ppmfc::CString name)
    {
        ImageDataMap& imageDatas = *reinterpret_cast<ImageDataMap*>(0x72CBC8);
        auto itr = imageDatas.find(name);
        if (itr == imageDatas.end())
            return false;
        return itr->second.pImageBuffer != nullptr;
    }

    static ImageDataClass* GetImageDataFromMap(ppmfc::CString name)
    {
        ImageDataMap& imageDatas = *reinterpret_cast<ImageDataMap*>(0x72CBC8);
        return ((ImageDataMapHelper*)&imageDatas)->GetImageDataFromMap(&name);
    }
};

class SomeDataMapHelper
{
private:
    bool* GetSomeDataFromMap(ppmfc::CString* ppName) { JMP_THIS(0x4767B0); }
public:
    static void SetSomeData(ppmfc::CString name, bool value)
    {
        SomeDataMap& someDatas = *reinterpret_cast<SomeDataMap*>(0x72A870);
        *((SomeDataMapHelper*)&someDatas)->GetSomeDataFromMap(&name) = value;
    }
};

class HSVClass;
class RGBClass
{
public:
	unsigned char R, G, B;

	operator int()
	{
		return RGB(R, G, B);
	}

    operator HSVClass() const;
};

class HSVClass
{
public:
    unsigned char H, S, V;

    operator RGBClass() const;
};