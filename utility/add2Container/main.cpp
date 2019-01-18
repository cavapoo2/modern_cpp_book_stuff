#include <iostream>
#include <vector>
#include <iterator>
#include "add2Container.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    std::vector<int> v;
    push_back_r(v, 1, 2, 3, 4);
    std::copy(std::begin(v), std::end(v),
              std::ostream_iterator<int>(std::cout, " "));
    std::vector<double> d;
    cout << "\n";
    push_back_l(d, 5.7,6.1,7.3,8.4);
    std::copy(std::begin(d), std::end(d),
              std::ostream_iterator<double>(std::cout, " "));
}