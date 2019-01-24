#pragma once
#include <array>
using std::array;
namespace Reverse
{
array<unsigned short, 1 << 16> BuildTable()
{
    array<unsigned short, 1 << 16> res;
    for (int i = 0; i < (1 << 16); ++i)
    {
        res[i] = Reverse::reverseBits(i);
    }
    return res;
}
}