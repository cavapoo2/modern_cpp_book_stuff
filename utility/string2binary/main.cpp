#include "str2bin.hpp"
#include <assert.h>
int main()
{
    std::vector<unsigned char> expected{0xBA, 0xAD, 0xF0, 0x0D, 0x42};
    assert(hexstr_to_bytes("BAADF00D42") == expected);
    assert(hexstr_to_bytes("BaaDf00d42") == expected);
}