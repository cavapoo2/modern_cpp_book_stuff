#pragma once
#include<string>
#include<algorithm>
#include<iostream>

std::string toBinString(unsigned long long in ) {
    std::string res="";
    int count=0;
    while(in) {
        if (in & 1) {
            res.append("1");
            count++;
        }
        else res.append("0");
        in >>= 1;
    }
    std::reverse(res.begin(),res.end());
    std::cout << "num 1s=" << count << std::endl;
    return res; 
}
