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
    //find first 1 to get to MSB 
    size_t pos = res.find_first_of("1");
    if (pos != std::string::npos) {

        res = res.substr(pos);
    }
    std::reverse(res.begin(),res.end());
    //std::cout << "num 1s=" << count << std::endl;
    return res; 
}
