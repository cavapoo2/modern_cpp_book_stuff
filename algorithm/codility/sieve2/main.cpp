#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
using vi = vector<int>;
using mii = map<int,int>;
using mvi = map<int,vector<int>>;


template<typename Cont>
void show(const Cont& c) {
	for(const auto & v: c) {
		cout << v << ",";
	}
	cout << endl;

}
struct Data {
	mii c;
	int max;
//	mvi mv;
	mii cn;

};

void showData(const Data& d){

	cout << "max=" << d.max << endl;
	cout << "counts:" << endl;
	for(auto const& [key,val] : d.c){
		cout << key << ":" << val << endl;
	}
	/*
	cout << "divs vec" << endl;
	for(auto const& [key,val] : d.mv){
		cout << key << ":";
		for(auto const& v : val){
			cout << v << ",";
		}
		cout << endl;
	}*/
	cout << "cns:" << endl;
	for(auto const& [key,val] : d.cn){
		cout << key << ":" << val << endl;
	}

}

Data initMapSet(vi & A){
	int max=0;
	mii c;
	//mvi mv;
	mii cn;
	for(auto v : A){
		if(v > max)max = v;
		if(c.count(v) > 0) {
			c[v]++;
			cn[v]++;
		}else {
			c[v]=1;
			cn[v]=1;
		}
//		mv[v].push_back(v);

	}
	//Data res = {c,max,mv,cn};
	Data res = {c,max,cn};
	return res;

}

Data divisors(Data& d){

	int i=2;
	while (i*i <= d.max){
		int k = i*i;
		while(k <= d.max) {
			if(d.c.count(k) > 0 ) {
			//	vi v(d.c[i],i); //init a vector of size and value
			//	d.mv[k].insert(d.mv[k].end(),v.begin(),v.end());
				d.cn[k]+= d.c[i];
				if(d.c.count(k/i) > 0 && (i != k/i)){
				//	vi v1(d.c[k/i],k/i);
				//	d.mv[k].insert(d.mv[k].end(),v1.begin(),v1.end());
					d.cn[k]+= d.c[k/i];
				}
			}
			k+=i;
		}
		i+=1;
	}
	return d; 

}

vi solutionSlow(vi& A){
	vi res;
	for(size_t i=0; i < A.size();++i){
		int count=0;
		for(size_t j=0; j < A.size(); ++j){
			if(j == i){
				continue;
			}
			if((A[i] % A[j]) != 0){
				count++;
			}
		}
		res.push_back(count);
	}
	return res;
}
//still 0.1 ms too slow - needs optimizing
vector<int> solution(vector<int>& vec){
	Data d = initMapSet(vec);
//	showData(d);
	d= divisors(d);
//	showData(d);
	vi res;
	int ones = d.c.count(1) > 0 ? d.c[1] : 0;
	int N = vec.size();
	for(auto v : vec){
		//int count = N - ones -  ((v != 1) ? d.mv[v].size() : 0);
		int count = N - ones -  ((v != 1) ? d.cn[v] : 0);
		res.push_back(count);
	}
	return res;
	//	show(res);

}

int main(int arg, char* argv[])
{
	vi test = {3,1,2,3,6};
	/*
		 Data d = initMapSet(test);
		 showData(d);
		 d= divisors(d);
		 cout << "final" << endl;
		 showData(d);
		 cout << "res" << endl;*/
	cout << "test {3,1,2,3,6}" << endl;
	vi res = solution(test);
	cout << "input {3,1,2,3,6}" << endl;
	show(res);
	vi res1 = solutionSlow(test);

	cout << "slow input {3,1,2,3,6}" << endl;
	show(res1);
	cout << "input {2,4}" << endl;
	test = {2,4};
	res = solution(test);
	
	show(res);
	cout << "slow {2,4}" << endl;
	res1 = solutionSlow(test);
	show(res1);

	test = {7,3,5,2,1,1,2,3,8};
	cout << "input {7,3,5,2,1,1,2,3,8}" << endl;
	res = solution(test);
	show(res);
	cout << "slow input {7,3,5,2,1,1,2,3,8}" << endl;
	res = solutionSlow(test);
	show(res);




	return 0;
}

