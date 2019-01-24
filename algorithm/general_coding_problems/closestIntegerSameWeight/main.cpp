#include <iostream>
#include <cassert>
#include "closestSM.hpp"
#include "int2BinString.hpp"

#include <random>
#include <limits>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstdlib>

using std::default_random_engine;
using std::numeric_limits;
using std::random_device;
using std::uniform_int_distribution;
using namespace std;

int main(int argc, char *argv[])
{
    default_random_engine gen((random_device())());
    for (int i = 0; i < 1000; i++)
    {
        using ll = long long;
        uniform_int_distribution<ll> dis(0, numeric_limits<ll>::max());
        uniform_int_distribution<short> bits(0, numeric_limits<ll>::digits);
        ll x = dis(gen);
        short b1 = bits(gen), b2 = bits(gen);
        ll testr=0,bestr=0;
        try
        {
            testr = ClosestSW::closestSWTest(x, b1, b2);
            bestr = ClosestSW::closestSW(x);
        }
        catch (const std::invalid_argument &ia)
        {
            std::cerr << "Invalid input: " << ia.what() << '\n';
            continue;
        }
        cout << "in=" << x << ",bestr=" << bestr << ",testr=" << testr << endl;
        ll test = llabs(x - testr);
        ll best = llabs(x - bestr);
        cout << "in=" << x << ",best=" << best << ",rand=" << test << ",b1=" << b1 << ",b2=" << b2 << endl;
        assert(best <= test);
    }

    return 0;
}