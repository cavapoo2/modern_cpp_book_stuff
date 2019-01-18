#include <iostream>
#include <vector>
#include <iterator>
#include "contains.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    std::vector<int> v{1,2,3,4,5,6,7};
    cout << contains(v,5) << endl;
    cout << contains(v,50) << endl;
    cout << contains_any(v,10,20,30) << endl;
    cout << contains_any(v,10,3,30) << endl;


    /*
    push_back_r(v, 1, 2, 3, 4);
    std::copy(std::begin(v), std::end(v),
              std::ostream_iterator<int>(std::cout, " "));
    std::vector<double> d;
    cout << "\n";
    push_back_l(d, 5.7,6.1,7.3,8.4);
    std::copy(std::begin(d), std::end(d),
              std::ostream_iterator<double>(std::cout, " "));
              */
}