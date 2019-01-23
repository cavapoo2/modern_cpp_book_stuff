#pragma once
using ll = unsigned long long;
namespace SwapBits
{
ll swapBits(ll data, short b1, short b2)
{

    if (((data >> b1) & 1) != ((data >> b2) & 1))
    { // bits are different
        ll n = (1 << b2) | (1 << b1);
        return data ^ n;
    }
    return data;
}
}
