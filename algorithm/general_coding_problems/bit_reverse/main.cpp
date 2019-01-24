#include <iostream>
#include <cassert>
#include "reverseBits.hpp"
#include "reverseBits2.hpp"
#include "int2BinString.hpp" 

#include <random>
#include <limits>
#include <cassert>
#include <algorithm>
#include <string>

using std::default_random_engine;
using std::numeric_limits;
using std::random_device;
using std::uniform_int_distribution;
using namespace std;

int main(int argc, char *argv[])
{
   // std::cout << std::numeric_limits<usi>::digits << std::endl;
    //std::cout << std::numeric_limits<unsigned long long>::digits << std::endl;
    using ull = unsigned long long;
    default_random_engine gen((random_device())());
    for (int i = 0; i < 1000; i++)
    {
        uniform_int_distribution<unsigned long long> dis(0, numeric_limits<unsigned long long>::max());
        unsigned long long x = dis(gen);
        ull rev = Reverse2::reverseBits(x);
        string origString =Utility::toBinString(x);
        string revString = Utility::toBinString(rev);
        string temp(revString);
        std::reverse(revString.begin(),revString.end());
        assert(origString.compare(revString) == 0 );

        cout << "x=" << origString << ",rev= " << temp << endl;

    }

    return 0;
}