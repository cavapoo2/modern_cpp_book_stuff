#include<iostream>
#include<random>
#include<limits>
#include<cassert>
#include<algorithm>
#include<string>
#include "parity1.hpp"
#include "parity2.hpp"
#include "parity3.hpp"

using std::default_random_engine;
using std::numeric_limits;
using std::random_device;
using std::uniform_int_distribution;

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

using namespace std;
int main(void ) {
    unsigned long long test1 = 0b1010;
    cout << Parity1::parity(test1) << endl;
    cout << Parity2::parity(test1) << endl;
    cout << Parity3::parity(test1) << endl;

    test1 = 0b10101;
    cout << Parity1::parity(test1) << endl;
    cout << Parity2::parity(test1) << endl;
    cout << Parity3::parity(test1) << endl;

    default_random_engine gen((random_device())());
    for(int i =0; i < 1000; i++) {
        uniform_int_distribution<unsigned long long> dis(0, numeric_limits<unsigned long long>::max());
        unsigned long long x = dis(gen);
        assert(Parity1::parity(x) == Parity3::parity(x));
        assert(Parity1::parity(x) == Parity2::parity(x));
        cout << "x=" << x << ",parity = " << Parity3::parity(x) << endl;
    }
  

    return 0;
}