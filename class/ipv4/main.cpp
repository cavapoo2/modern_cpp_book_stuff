#include "ipv4.hpp"
#include "get_args.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char* argv[])
{
   ipv4 a(168, 192, 0, 1);
   std::cout << a << std::endl;
   std::cout << a.to_string() << std::endl;

   ipv4 b = a;
   ipv4 c;
   c = b;

   ipv4 ip;
   std::cout << ip << std::endl;
   std::cin >> ip;
   if(!std::cin.fail())
      std::cout << ip << std::endl;
   //test vector
   cout << "getting the command line ip addresses" << endl;
   vector<ipv4> ips = getCommandLineArgs<ipv4>(argc,argv);
   sort(ips.begin(),ips.end());
   for(auto &ip : ips) {
      cout << ip << endl;
   }   
}