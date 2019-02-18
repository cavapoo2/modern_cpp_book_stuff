/*An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

	For example, consider array A such that

	A[0] = 3    A[1] = 4    A[2] =  3
	A[3] = 2    A[4] = 3    A[5] = -1
	A[6] = 3    A[7] = 3
	The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

	Write a function

	int solution(vector<int> &A);

	that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

	For example, given array A such that

	A[0] = 3    A[1] = 4    A[2] =  3
	A[3] = 2    A[4] = 3    A[5] = -1
	A[6] = 3    A[7] = 3
	the function may return 0, 2, 4, 6 or 7, as explained above.

	Write an efficient algorithm for the following assumptions:

	N is an integer within the range [0..100,000];
	each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
	*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<limits>
using namespace std;
int getLeader(vector<int> &A) {
	map<int,vector<int>> mv;
	int max=0;
	int winidx=-1;
	for(int i=0; i < A.size(); ++i) {

		if(mv.count(A[i]) > 0){
			mv[A[i]].push_back(i);
			if(mv[A[i]].size() > max) {
				max = mv[A[i]].size();
				winidx = i;
			}
		}else {
			vector<int> idx = {i};
			mv[A[i]] = idx;
			if(max == 0){
				max =1;
				winidx=i;
			}
		}

	}
	int limit = A.size()/2 +1;
	if(max >= limit) return winidx; 
	return - 1;
}

int solution(vector<int> &A){
	if (A.size() == 0) return -1;
	int d = getLeader(A);
	return d;

}

int main(int arg, char* argv[])
{
	cout << numeric_limits<int>::min() << "," << numeric_limits<int>::max() << endl;
	vector<int> d = {3,4,3,2,3,-1,6,3};
	int res = solution(d);
	cout << res << endl;
	d = {3,4,3,2,3,-1,3,3};
	res = solution(d);
	cout << res << endl;
	d = {2, 1, 1, 3, 4};
	res = solution(d);
	cout << res << endl;
	d = {1, 1, 1, 3, 4};
	res = solution(d);
	cout << res << endl;
	d = { 2147483647};
	res = solution(d);
	cout << res << endl;
	return 0;
}

