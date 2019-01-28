/*
 *This is a demo task.

Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
 */
#include<algorithm>
#include<vector>
using namespace std;
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	sort(A.begin(),A.end());
	vector<int>::iterator iter = find_if(A.begin(),A.end(), [] (const int i) { return  i > 0 ;} );

	if(iter == A.end()) return 1;
	int count=1;
	int prev = 1;
	while(iter != A.end()) {
		//   cout << *iter++ << endl;
		prev = *iter;
		if(*iter++ != count) return count;
		if(prev != *iter)
			count++;

	}
	return count;

}
