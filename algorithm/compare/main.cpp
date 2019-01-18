#include <iostream>
#include "compare.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    cout << minimumc(std::less<>(), 3, 2, 1, 0) << endl;

}