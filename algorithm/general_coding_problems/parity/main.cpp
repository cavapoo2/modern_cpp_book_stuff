#include<iostream>
#include "parity1.hpp"
#include "parity2.hpp"
#include "parity3.hpp"
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
  
    return 0;
}