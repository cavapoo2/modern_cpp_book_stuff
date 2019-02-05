/*A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(char *S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
*/
#include<iostream>
#include<stack>
#include<map>
#include<string>


using namespace std; 
int solution(string &S) {
  if(S.empty()) return 1;
  map<char,char> mc = {{')','('},{']','['},{'}','{'}};
  stack<char> stk;
  for(int i=0; i < S.size(); ++i){
    if((S[i] == '(') || S[i] == '{' || S[i] == '['){
      stk.push(S[i]);
    }else {
      if(stk.empty()) return 0;
      char v = stk.top();
      if (v != mc[S[i]]) return 0;
      stk.pop();
    }

  }
  if(!stk.empty()) return 0;
  return 1;

  //for(int i=0; i < S.
}
int main(int argc, char* argv[])
{
  string a = "{[()()]}";
  cout << solution(a) << endl;
  a = "([)()]";
  cout << solution(a) << endl;
  a = ")(";
  cout << solution(a) << endl;
  a = "{{{{";
  cout << solution(a) << endl;
  return 0; 
}

