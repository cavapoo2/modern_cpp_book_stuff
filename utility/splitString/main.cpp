#include<assert.h>
#include "split.hpp"
int main()
{
   using namespace std::string_literals;

   std::vector<std::string> expected{"this", "is", "a", "sample"};

   assert(expected == split("this is a sample"s, ' '));
   assert(expected == split("this,is a.sample!!"s, ",.! "s));
}