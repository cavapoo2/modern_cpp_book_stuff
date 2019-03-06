/*
 *Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.

You start to eat the chocolates. After eating a chocolate you leave only a wrapper.

You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.

More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).

You stop eating when you encounter an empty wrapper.

For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.

The goal is to count the number of chocolates that you will eat, following the above rules.

Write a function:

int solution(int N, int M);

that, given two positive integers N and M, returns the number of chocolates that you will eat.

For example, given integers N = 10 and M = 4. the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..1,000,000,000].
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi = vector<int>;


template<typename Cont>
void show(const Cont& c) {
	for(const auto & v: c) {
		cout << v << ",";
	}
	cout << endl;

}
int gcdS(int a, int b) {
    if(a == b) return a;
    if(a > b) return gcdS(b,a-b);
    else return gcdS(a,b-a);
}
int gcd(int a, int b, int res) {
	if (a == b) return res * a;
	else if((a % 2 == 0) && (b % 2 == 0)){
		return gcd( a >> 1, b >> 1, res << 1);
	}else if(a % 2 == 0){
		return gcd(a >> 1,b,res); 
	}else if(b % 2 == 0){
		 return gcd(a,b >> 1, res);
	}else if(a > b) {
		return gcd(b,a-b,res);
	}else {
		return gcd(a,b-a,res);
	}

}

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    if(N % M == 0) return N/M;
		else return N / gcd(N,M,1);
}

int main(int arg, char* argv[])
{
	cout << gcdS(10,4) << endl;
	cout << gcd(10,4,1) << endl;
	cout << solution(10,4) << endl;
  return 0;
}

