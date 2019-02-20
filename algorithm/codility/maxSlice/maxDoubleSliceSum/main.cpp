/*
 *A non-empty array A consisting of N integers is given.

 A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

 The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

 For example, array A such that:

 A[0] = 3
 A[1] = 2
 A[2] = 6
 A[3] = -1
 A[4] = 4
 A[5] = 5
 A[6] = -1
 A[7] = 2
 contains the following example double slices:

 double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
 double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
 double slice (3, 4, 5), sum is 0.
 The goal is to find the maximal sum of any double slice.

 Write a function:

 int solution(vector<int> &A);

 that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.

 For example, given:

 A[0] = 3
 A[1] = 2
 A[2] = 6
 A[3] = -1
 A[4] = 4
 A[5] = 5
 A[6] = -1
 A[7] = 2
 the function should return 17, because no double slice of array A has a sum of greater than 17.

 Write an efficient algorithm for the following assumptions:

 N is an integer within the range [3..100,000];
 each element of array A is an integer within the range [−10,000..10,000].
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename Cont>
void show(const Cont& c){
	for(auto v : c){
		cout << v << ",";
	}
	cout << endl;
}

int solution(vector<int> &A) {
	//get left max
	if(A.size() == 3) return 0;
	vector<int> subl(A.size(),0);
	for(int i=1; i < A.size()-1;++i) {
		subl[i]=std::max(0,A[i] + subl[i-1]);
	}

//	show(subl);
	vector<int> subr(A.size(),0);
	for(int i=A.size()-2; i > 0; --i)
	{
		subr[i]=std::max(0,A[i] + subr[i+1]);
	}
	//show(subr);
	int maxs=0;
	for(int i=1; i < (A.size()-1); ++i)
	{
		int sum = subl[i-1] + subr[i+1];
	//	cout << subl[i-1] << "+" << subr[i+1] <<  "=" << sum << endl; 
		if(sum > maxs){
			maxs = sum;
		}
	}
	return maxs;

}

int main(int arg, char* argv[])
{
	vector<int> test = {3,2,6,-1,4,5,-1,2};
	show(test);
	int res = solution(test);
	cout << "res=" << res << endl;
	test = {5,0,1,0,5};
	res = solution(test);
	cout << "res=" << res << endl;

	test = {0,10,-5,-2,0};
	res = solution(test);
	cout << "res=" << res << endl;
	cout << "should be 26 " << endl;
	test = {6, 1, 5, 6, 4, 2, 9, 4}; // should be 26
	show(test);
	res = solution(test);
	cout << "res=" << res << endl;

	return 0;
}

