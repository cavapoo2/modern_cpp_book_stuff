#pragma once
namespace Parity1 {
      short parity(unsigned long long in) {
        short res = 0; // 1 is odd 0 is even
        while(in) {
            res ^= (in & 1);
            in >>= 1;
        } 
        return res;
    }
}