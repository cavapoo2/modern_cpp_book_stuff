/*
 *A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.

For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).

Write a function:

int solution(int N);

that, given a positive integer N, returns the number of its factors.

For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int solution(int N) {
	using ull = unsigned long long;
	ull i =1LL;
	ull NL = static_cast<ull>(N);
	int count=0;
	while( (i*i) < NL){
		if((NL % i) == 0)count+=2;
		i++;
	}
	if((i*i) == NL) count++;
	return count;

}

int main(int arg, char* argv[])
{
	cout << "10=" << solution(10) << endl;
	cout << "12=" << solution(12) << endl;
	cout << "20=" << solution(20) << endl;

  return 0;
}

