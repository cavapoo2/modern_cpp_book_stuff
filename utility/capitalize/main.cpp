#include<assert.h>
#include<iostream>
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
/*
	 assert(L"THIS SHOULD BE ALL UPPERCASE!"s == 
			 uppercase(L"This should be all uppercase!"s));
			 */
	using namespace std;
	string test = "This should be all uppercase!";
	string res = uppercase<char>(test);
	cout << "res = " << res << endl;
	res = caseChange<char>(test,true);
	cout << "res = " << res << endl;
	res = caseChange<char>(test,false);
	cout << "res = " << res << endl;
cout << test << endl;





	 return 0;
}
