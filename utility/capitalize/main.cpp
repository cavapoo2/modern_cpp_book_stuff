#include<assert.h>
#include"capitalize.hpp"
int main()
{
   using namespace std::string_literals;

   std::string text = "THIS IS an ExamplE, should wORk!";
   std::string expected = "This Is An Example, Should Work!";
   assert(expected == capitalize(text));
   
   assert(
          L"The C++ Challenger"s ==
          capitalize(L"the c++ challenger"s));
   
   assert(
      L"This Is An Example, Should Work!"s == 
      capitalize(L"THIS IS an ExamplE, should wORk!"s));
}