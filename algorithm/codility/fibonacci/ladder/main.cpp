/*
 *You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:

with your first step you can stand on rung 1 or 2,
if you are on rung K, you can move to rungs K + 1 or K + 2,
finally you have to stand on rung N.
Your task is to count the number of different ways of climbing to the top of the ladder.

For example, given N = 4, you have five different ways of climbing, ascending by:

1, 1, 1 and 1 rung,
1, 1 and 2 rungs,
1, 2 and 1 rung,
2, 1 and 1 rungs, and
2 and 2 rungs.
Given N = 5, you have eight different ways of climbing, ascending by:

1, 1, 1, 1 and 1 rung,
1, 1, 1 and 2 rungs,
1, 1, 2 and 1 rung,
1, 2, 1 and 1 rung,
1, 2 and 2 rungs,
2, 1, 1 and 1 rungs,
2, 1 and 2 rungs, and
2, 2 and 1 rung.
The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.

Write a function:

vector<int> solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].

For example, given L = 5 and:

    A[0] = 4   B[0] = 3
    A[1] = 4   B[1] = 2
    A[2] = 5   B[2] = 4
    A[3] = 5   B[3] = 3
    A[4] = 1   B[4] = 1
the function should return the sequence [5, 1, 8, 0, 1], as explained above.

Write an efficient algorithm for the following assumptions:

L is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..L];
each element of array B is an integer within the range [1..30].
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

int helper(int rungs, int mod, int rung, int acc) {

	if(rung > rungs) return acc;

	if(rung == rungs){
		acc = (acc + 1) % mod;
		return acc;
	}
	int resa = helper(rungs,mod,rung+1,acc);
	int resb = helper(rungs,mod,rung+2,acc);

	return resa + resb;

}

//dumb first attempt lol
vector<int> solution2(vector<int> &A, vector<int> &B){
	vi res;
	for(int i=0; i < B.size(); ++i){
		int rungs = A[i];
		int mod = 1 << B[i];
		int resa = helper(rungs,mod,1,0);
		int resb = helper(rungs,mod,2,0);
		cout << rungs << "," << mod << ":" << resa << "+" << resb << "=" << ((resa+resb) % mod) << endl;
		res.push_back((resa+resb) % mod);
	}
	return res;
}

vi fib(int n, int m){

	vi res={1 % m,1 % m};
	for(int i=2; i <=n; ++i){
		res.push_back((res[i-1] + res[i-2]) % m);
	}
	return res;
}


vector<int> solution(vector<int> &A, vector<int> &B){
	int maxA = 0;
	int maxB = 0;
	for(int i=0; i < B.size(); ++i){
		if(A[i] > maxA) maxA=A[i];
		if(B[i] > maxB) maxB = B[i];
	}

	vi fb = fib(maxA,(1 << maxB));
	vi res;
	for(int i =0; i < A.size();++i){
		int a = fb[A[i]];
		if(B[i] != maxB) a = a % (1 << B[i]);
		res.push_back(a);

	}
	return res;

}


int main(int arg, char* argv[])
{
	
	vi A = {4,4,5,5,1,6,7};
	vi B = {3,2,4,3,1,4,5};

	vi res = solution(A,B);
	show(res);

	/*
	vi fibr = fib(100, (1 << 4));
	show(fibr);
*/
  return 0;
}

