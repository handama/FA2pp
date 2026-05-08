#pragma once

#include "FA2PP.h"

struct ColorStruct
{
    unsigned char red, green, blue;
};

struct BGRStruct 
{ 
    BGRStruct(unsigned char b = 0, unsigned char g = 0, unsigned char r = 0)
    {
        B = b;
        G = g;
        R = r;
        Zero = 0;
    }
    BGRStruct(ColorStruct color)
    {
        R = color.red;
        G = color.green;
        B = color.blue;
        Zero = 0;
    }
    BGRStruct(COLORREF color)
    {
        R = GetRValue(color);
        G = GetGValue(color);
        B = GetBValue(color);
        Zero = 0;
    }

    unsigned char B, G, R, Zero;
    bool operator< (const BGRStruct& rhs) const { return *(int*)this < *(int*)&rhs; }
    bool operator==(const BGRStruct& rhs) const { return *(int*)this == *(int*)&rhs; }
};

namespace std
{
    template<>
    struct hash<BGRStruct> {
        size_t operator()(const BGRStruct& s) const noexcept {
            return std::hash<int>()(*reinterpret_cast<const int*>(&s));
        }
    };
}

class BytePalette
{
public:
    static constexpr reference<int, 0x884034> const LoadedPaletteCount{};
    static constexpr reference<int, 0x81E098, 254> const LoadedPaletteFlag{};
    static constexpr reference<BytePalette, 0x7EDD9C, 255> const LoadedPalettes{}; // count is not sure in fact

    ColorStruct Data[256];

    ColorStruct& operator[](int index) { return Data[index]; }
};

class Palette
{
public:
    static constexpr constant_ptr<Palette, 0x72B4C4> PALETTE_UNIT{};
    static constexpr constant_ptr<Palette, 0x72B8C4> PALETTE_ISO{};
    static constexpr constant_ptr<Palette, 0x72ACC4> PALETTE_THEATER{};
    static constexpr constant_ptr<Palette, 0x72A8C4> PALETTE_LIB{};

    BGRStruct Data[256];

    BGRStruct& operator[](int index) { return Data[index]; }
    ColorStruct GetByteColor(int index) { // It's BGR color
        ColorStruct ret;
        BGRStruct& tmp = *(BGRStruct*)&Data[index];
        ret.red = tmp.R;
        ret.green = tmp.G;
        ret.blue = tmp.B;
        return ret;
    }
};