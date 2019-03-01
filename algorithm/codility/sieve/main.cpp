/*
 * A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

 A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

 You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

 Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

 For example, consider an integer N = 26 and arrays P, Q such that:

 P[0] = 1    Q[0] = 26
 P[1] = 4    Q[1] = 10
 P[2] = 16   Q[2] = 20
 The number of semiprimes within each of these ranges is as follows:

 (1, 26) is 10,
 (4, 10) is 4,
 (16, 20) is 0.
 Write a function:

 class Solution { public int[] solution(int N, int[] P, int[] Q); }

 that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

 For example, given an integer N = 26 and arrays P, Q such that:

 P[0] = 1    Q[0] = 26
 P[1] = 4    Q[1] = 10
 P[2] = 16   Q[2] = 20
 the function should return the values [10, 4, 0], as explained above.

 Write an efficient algorithm for the following assumptions:

 N is an integer within the range [1..50,000];
 M is an integer within the range [1..30,000];
 each element of arrays P, Q is an integer within the range [1..N];
 P[i] ≤ Q[i].
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using si = set<int>;

template<typename Cont>
void show(const Cont& c) {
	for(const auto & v: c) {
		cout << v << ",";
	}
	cout << endl;

}

vi arrayF(int N) {
	vi res(N+1,0);
	int i=2;
	while(i*i <= N){
		//		cout << "in=" << i << endl;
		if(res[i]==0){

			int k = i*i;
			while(k <= N){
				if(res[k]==0){
					res[k]=i;
				}
				k+=i;
			}
		}
		i+=1;
	}
	return res;
}


//get the running semi primes
si  semi(int N){
	vb t(N+1,true);
	int i=2;
	while(i*i <= N){
		if(t[i]==true){
			int k = i*i;
			while(k <= N){
				if(t[k] == true) {
					t[k]=false; //indicate its not prime
				}
				k+=i;
			}
		}
		i+=1;
	}
	i=2;
	si res;
	//	show(t);
	while(i*i <= N) {
		if(t[i] == true){//prime only

			int k = i*i;
			while(k <= N){
				if(t[k/i] == true) {
					//		cout << "k=" << k << ",i=" << i << ",k/i = " << k/i << endl;
					res.insert(k);
				}
				k+=i;
			}
		}
		i=i+1;
	}
	return res;
}

vi genPrefix(const si& s,int N){
	vi res = {0,0,0,0,1};
	for(int i = 5; i  <= N; ++i) {
		if(s.find(i) != s.end()){
			res.push_back(res[res.size()-1]+1);
		}else {
			res.push_back(res[res.size()-1]);
		}
	}
	return res;


}
vector<int> solution(int N, vector<int>&P, vector<int>&Q){
	si s = semi(N);
	vi pfx = genPrefix(s,N);	
	vi res;
	//	cout << "pfx= " << endl;
	//	show(pfx);
	for(int i=0; i < P.size(); ++i){
		//	cout << "Q[i]=" << Q[i] << ",pfx[Q[i]]=" << pfx[Q[i]] << ",P[i]= " << P[i] << ",pfx[P]=" << pfx[P[i]] << endl;
		int count = pfx[Q[i]] - pfx[P[i]-1];
		res.push_back(count);
	}
	return res;

}
/*
	 vector<int> solution(int N,vector<int> &P, vector<int> &Q){
	 vi ref = arrayF(N);
	 vi res;
	 for(int i=0; i < P.size(); ++i){
	 int from = P[i];
	 int to = Q[i];
	 int count=0;
	 for(int val = from; val <= to; ++val){
	 if(ref[val]==0)continue;
	 int s = ref[val];
	 int r = val/s;
	 if(ref[r] == 0) {
	 count++;
	 }
	 }
	 res.push_back(count);
	 }
	 return res;
	 }*/
/*
	 P[0] = 1    Q[0] = 26
	 P[1] = 4    Q[1] = 10
	 P[2] = 16   Q[2] = 20
	 */

int main(int arg, char* argv[])
{
	int N = 26;
	vi p = {1,4,16};
	vi q = {26,10,20};
	vi res =  solution(N,p,q);
	show(res);

	return 0;
}

