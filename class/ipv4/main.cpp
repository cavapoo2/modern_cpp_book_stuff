#include "ipv4.hpp"
#include<iostream>
int main()
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
}