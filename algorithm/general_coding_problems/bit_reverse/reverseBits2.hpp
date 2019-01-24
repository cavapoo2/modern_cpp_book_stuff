#pragma once
#include <array>
#include "reverse_table.hpp"
#include "int2BinString.hpp" // co
using std::array;
namespace Reverse2
{
using usi = unsigned short int;
using ull = unsigned long long; //64 bit on this machine
static std::array<usi, 1 << 16> tab = Reverse::BuildTable();

ull reverseBits(ull in)
{
    const usi mask = 0xFFFF;

    ull toptop = static_cast<ull>(tab[in & mask]) << 48;
    ull toplow = static_cast<ull>(tab[(in >> 16) & mask]) << 32;
    ull lowtop = (static_cast<ull>(tab[(in >> 32) & mask]) << 16);
    ull lowlow  = static_cast<ull>(tab[(in >> 48)]);
    return toptop | toplow | lowtop | lowlow;
    /*
    using namespace std;
    cout << "tt=" << Utility::toBinString(toptop) << endl;
    cout << "tl=" << Utility::toBinString(toplow) << endl;
    cout << "lt=" << Utility::toBinString(lowtop) << endl;
    cout << "ll=" << Utility::toBinString(lowlow) << endl;
    */
 
}
}