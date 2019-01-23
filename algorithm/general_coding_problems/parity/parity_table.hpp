#pragma once
#include <array>
using std::array;
namespace ParityUtil
{
array<short, 1 << 16> BuildTable()
{
    array<short, 1 << 16> res;
    for (int i = 0; i < (1 << 16); ++i)
    {
        res[i] = Parity1::parity(i);
    }
    return res;
}
}