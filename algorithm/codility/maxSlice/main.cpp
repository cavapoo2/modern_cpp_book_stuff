/*A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

	Write a function:

	int solution(vector<int> &A);

	that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

	For example, given array A such that:

	A[0] = 3  A[1] = 2  A[2] = -6
	A[3] = 4  A[4] = 0
	the function should return 5 because:

	(3, 4) is a slice of A that has sum 4,
	(2, 2) is a slice of A that has sum −6,
	(0, 1) is a slice of A that has sum 5,
	no other slice of A has sum greater than (0, 1).
	Write an efficient algorithm for the following assumptions:

	N is an integer within the range [1..1,000,000];
	each element of array A is an integer within the range [−1,000,000..1,000,000];
	the result will be an integer within the range [−2,147,483,648..2,147,483,647].
	*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
int solution(vector<int> &A){ 

	int limit=0;
	int max=-1000000;
	int negmin=-1000000;
	int pos = false;
	for(const auto v : A){
		if (v >= 0) pos=true;
		if(pos){
			limit = std::max(0, limit + v);
			max = std::max(max,limit);
		}
		if(v > negmin && !pos) negmin = v;
	}
	return pos  ? max : negmin;
}
/* too slow this one*/
int solution1(vector<int>& A) {
	int max = -1000000;
	for(int i=0; i < A.size(); ++i) {
		int sum = 0;
		for(int j=i; j < A.size(); j++) {
			sum+= A[j];
			if(sum > max)max = sum;
		}
	}
	return max;
}

int main(int arg, char* argv[])
{
	vector<int> d = {3,2,-6,4,0};
	int res = solution1(d);
	cout << res << endl;
	res= solution(d);
	cout << res << endl;
	d = {-10};
	res= solution(d);
	cout << res << endl;
	return 0;
}

