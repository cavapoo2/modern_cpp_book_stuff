/*
 *
 A non-empty array A consisting of N integers is given.

 The leader of this array is the value that occurs in more than half of the elements of A.

 An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

 For example, given array A such that:

 A[0] = 4
 A[1] = 3
 A[2] = 4
 A[3] = 4
 A[4] = 4
 A[5] = 2
 we can find two equi leaders:

 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
 The goal is to count the number of equi leaders.

 Write a function:

 int solution(vector<int> &A);

 that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

 For example, given:

 A[0] = 4
 A[1] = 3
 A[2] = 4
 A[3] = 4
 A[4] = 4
 A[5] = 2
 the function should return 2, as explained above.

 Write an efficient algorithm for the following assumptions:

 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<limits>
using namespace std;

struct Data {
	map<int,int> m;
	int leader;
	int count;
};

Data getData(vector<int>&A) {
	Data d;
	d.leader = numeric_limits<int>::min();
	d.count=0;
	for(auto v : A){
		if(d.leader == v) {
			d.count++;
		}
		else if(d.count == 0)
		{
			d.leader = v;
			d.count++;
		}else {
			d.count--;
		}
		if(d.m.count(v) == 0){
			d.m[v]=1;
		}else {
			d.m[v]++;
		}
	}
	return d;
}
int solution(vector<int> &A){

	Data d = getData(A);
	if (d.count <= 0) return 0;
	int sols=0;
	int count=0;
	int rcount = d.m[d.leader];
	//	cout << d.leader << endl;

	for(int i =0; i < A.size(); ++i) 
	{
		int lavg = (i+1) /2 + 1;
		int ravg = (A.size()-(i+1))/2 + 1;
		cout << "lavg=" << lavg << ",ravg=" << ravg << endl;
		if(A[i] == d.leader){
			count++;
			rcount = d.m[d.leader] - count;
		}

		if(count >= lavg && rcount >= ravg)
		{
			cout << "yes" << endl;
			sols++;
		}
		else {
			cout << "no" << endl;
		}


	}
	return sols;


}
int main(int arg, char* argv[])
{
	vector<int> d = {4,3,4,4,4,2};
	int res = solution(d);
	cout << res << endl;
	cout << "other" << endl;
	d = {4, 4, 2, 5, 3, 4, 4, 4};
	res = solution(d);
	cout << res << endl;
	return 0;
}

