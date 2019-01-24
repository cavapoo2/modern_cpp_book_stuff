#pragma once
#include <limits>
#include <iostream>

namespace ClosestSW
{

using ll = unsigned long long;

ll closestSW(ll in)
{
    //iterate from lsb looking for first difference
    using namespace std;
    for (int i = 0; i < (std::numeric_limits<ll>::digits) - 1; i++)
    {
        if (((in >> i) & 1) ^ ((in >> (i + 1)) & 1))
        {
            ll bits = ((in << i) & 1) | ((in << (i + 1)) & 1);
            return in ^ bits;
        }
        else
        {
            throw invalid_argument("all bits are the same");
        }
    }
    return 0;
}
//this is just to try some random bit pair change to prove the above gives
// best min (abs(y-x)) with original value 
ll closestSWTest(ll in, int i, int j)
{
    if (((in >> i) & 1) != ((in >> j) & 1))
    {
        ll bits = (1 << i) | (1 << j);
        in ^= bits;
        return in;
    }
    else
    {
        return closestSW(in);
    };
}
}