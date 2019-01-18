#include "array2d.hpp"
#include "get_args.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char* argv[])
{
  array2d<int,3,3> a2d;
  a2d.fill(100); 
  cout << a2d << endl;

  array2d<double,3,3> a2dd{1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
  cout << "double matrix" << endl;  
  cout << a2dd << endl;
}