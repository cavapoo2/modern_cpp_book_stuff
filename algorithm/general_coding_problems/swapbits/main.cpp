#include "swapbits.hpp"
#include <cassert>
#include "int2BinString.hpp" // could put these type of things in a flat util file ?
#include <iostream>

using std::cout;
using std::endl;
using std::numeric_limits;

using namespace std;
void SimpleTest()
{
    assert(SwapBits::swapBits(47, 1, 4) == 61);
    assert(SwapBits::swapBits(28, 0, 2) == 25);
}

int main(int argc, char *argv[])
{

    ll test1 = 0b100100;
    ll res = SwapBits::swapBits(test1, 0, 5);
    cout << toBinString(res) << endl;
    SimpleTest();
    return 0;
}