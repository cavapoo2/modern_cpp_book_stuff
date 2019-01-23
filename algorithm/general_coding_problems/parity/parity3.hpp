#pragma once
#include "parity_table.hpp"
//#include<limits>
//#include<iostream>
//note my pc is 32bit, hence my unsigned long long is 64 bits
//maybe on a 64bit pc unsigned long is 64bit and unsigned long long is 128 bits
namespace Parity3 {

    static array<short,1 << 16> tab = ParityUtil::BuildTable();

    short parity( unsigned long long in) {
        
        const int mask = 0xFFFF;
        //std::cout << "bit size=" << std::numeric_limits<unsigned long long>::digits << std::endl;
        short res=0;
        res = (tab[(in >> 48)] ^
        tab[((in >> 32) & mask)] ^ 
        tab[((in >> 16) & mask)] ^ 
        tab[(in & mask)] );
        return res;
    }

}