/*
 *An integer N is given, representing the area of some rectangle.

 The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

 The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

 For example, given integer N = 30, rectangles of area 30 are:

 (1, 30), with a perimeter of 62,
 (2, 15), with a perimeter of 34,
 (3, 10), with a perimeter of 26,
 (5, 6), with a perimeter of 22.
 Write a function:

 int solution(int N);

 that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

 For example, given an integer N = 30, the function should return 22, as explained above.

 Write an efficient algorithm for the following assumptions:

 N is an integer within the range [1..1,000,000,000]. 
 */
#include<iostream>

#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int getPerim(int a, int N){
	int b = N / a;
	return  2* (a + b);

}

int solution(int N){

	using ul  = unsigned long long;
	ul NL = static_cast<ul>(N);
	ul i=1LL;
	int min = numeric_limits<int>::max();
	while(i*i <  NL){
		if(N % i == 0){
			int p = getPerim(static_cast<int>(i),N);
			if (p < min) min = p;
		}
		i++;
	}
	if(NL % i == 0) {
		int p = getPerim(static_cast<int>(i),N);
			if(p < min) min = p;
	}
	return min;

}

int main(int arg, char* argv[])
{
	int p = solution(30);
	cout << p << endl;
	return 0;
}

