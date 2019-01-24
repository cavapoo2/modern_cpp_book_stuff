#include <limits>
#include<array>
using usi = unsigned short int;
//this is a 16bit reverse

namespace Reverse {
usi reverseBits(usi in)
{
    for (int i = 0, j = 15; i < 16/2; ++i, --j)
    {
        if (((in >> i) & 1) != ((in >> j) & 1))
            {
                usi temp = (1 << j) | (1 << i);
                in ^= temp;
            }
    }
    return in;
}

    
}