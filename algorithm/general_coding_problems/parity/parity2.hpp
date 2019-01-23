#pragma once
namespace Parity2 {
    short parity(unsigned long long in) {
        short res = 0; // 1 is odd 0 is even
        while(in) {
            res ^= 1;
            in &= (in - 1);
        } 
        return res;
    }
}