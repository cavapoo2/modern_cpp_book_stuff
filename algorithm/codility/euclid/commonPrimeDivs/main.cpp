/*
 A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. For example, 2 and 5 are prime divisors of 20.

You are given two positive integers N and M. The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.

For example, given:

N = 15 and M = 75, the prime divisors are the same: {3, 5};
N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.
Write a function:

class Solution { public int solution(int[] A, int[] B); }

that, given two non-empty arrays A and B of Z integers, returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.

For example, given:

    A[0] = 15   B[0] = 75
    A[1] = 10   B[1] = 30
    A[2] = 3    B[2] = 5
the function should return 1, because only one pair (15, 75) has the same set of prime divisors.

Write an efficient algorithm for the following assumptions:

Z is an integer within the range [1..6,000];
each element of arrays A, B is an integer within the range [1..2,147,483,64
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

vi sieve(int N){
	int i=2;
	vi res(N+1,1);
	while(i * i <= N){

		int k = i*i;

		while(k <= N){
			res[k]=0;
			k+=i;
		}
		i+=1;
	}

	return res;
}

vi primes(int N){
	vi s = sieve(N);
	vi res;
	for(int i=1; i <= N; ++i){
		if(s[i] == 1) {
			res.emplace_back(i);
		}
	}
	return res;
}
int common(int a, int b, vi& s,int m){
//	vi s = sieve(m);
	vi res;
	for(int i=1; i <= m; ++i){
		if(s[i] == 1) {
			if(((a % i == 0) && (b % i != 0)) || ((a % i != 0) && (b % i == 0)))
				return 0;
		}
	}
	return 1;
}



int solution2(vector<int>&A, vector<int>&B){
	int count=0;
	int max=0;
	for(auto v : B){
		if(v > max) max = v;
	}
	vi s = sieve(max);
	for(int i=0; i < A.size(); ++i){
		int a = A[i];
		int b = B[i];
		//int m = std::max(a,b);
		count += common(a,b,s,max);
	}
	return count;
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

int lcm(int a, int b){
	return (a * b) / gcd(a,b,1);
}
int solution(vector<int>&A, vector<int>&B){
	int count=0;
	for(int i=0; i < A.size(); ++i){
		int d = gcd(A[i],B[i],1);
		if( d == 1 && A[i] != B[i]) continue;
		int a = A[i]/d;
		bool ok = true;
		while(a != 1){
			int t = gcd(a,d,1);
			if(t == 1) {
				ok = false;
				break;
			}
			a = a/t;
		}
		if(ok == false) continue;
		int b = B[i]/d;
		while(b != 1){
			int t = gcd(b,d,1);
			if(t == 1) {
				ok = false;
				break;
			}
			b = b/t;
		}
		if(ok == false) continue;
		count++;
	}
	return count;
}



int main(int arg, char* argv[])
{
/*
A[0] = 15   B[0] = 75
    A[1] = 10   B[1] = 30
    A[2] = 3    B[2] = 5
*/
	vi A = {15,10,3};
	vi B = {75,30,5};
	int res = solution(A,B);
	cout << res << endl;
	for(int i=0; i < A.size();++i){
		cout << A[i] << " and " << B[i] << ",gcd=" << gcd(A[i],B[i],1) << ",lcm=" << lcm(A[i],B[i]) << endl;
	}
	int res2 = solution2(A,B);
	cout << "res2= " << res2 << endl;

	A={15,10,3,28,105,203,100,1};
	B={75,30,5,56,512,478,1000,1};
	for(int i=0; i < A.size(); ++i){
		int r1 = solution(A,B);
		int r2 = solution2(A,B);
		cout << "r1=" << r1 << ",r2=" << r2 << endl;
	}

  return 0;
}

