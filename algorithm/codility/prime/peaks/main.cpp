#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

using vi = vector<int>;

template<typename C>
void show(const C & c){
	for(auto v : c){
		cout << v << ",";
	}
	cout << endl;
}

vi getPeaks(vi & v){
	vi res;
	for(int i=1; i < v.size()-1; ++i){
		if(v[i-1] < v[i] && v[i] > v[i+1])
			res.push_back(i);
	}
	return res;
}

int solution(vector<int>& A){
	vi peaks = getPeaks(A);
	int sz = peaks.size();
	if(peaks.empty()) return 0;
	else if(sz==1) return 1;
	//iterate on the block size
	for(int i= peaks.size(); i > 0; --i ) {
		if(A.size() % i != 0) continue;
		int blkSz = A.size()/i; //say we have 3 peaks, in blk of 12, blksz is 4
		vector<bool> vb(i,false);
		int count=0;
		for (auto peak : peaks){
			int blk = peak/blkSz; // which block it in
			if(vb[blk]==false){
				count++;
				vb[blk]=true;
			}
		}
		if(count == i)return count;

	}
	return 0;
}



int main(int arg, char* argv[])
{

	cout << "test 1,2,3,4,3,4,1,2,3,4,6,2" << endl;
	vi test = {1,2,3,4,3,4,1,2,3,4,6,2};
	show(getPeaks(test));
	cout << solution(test) << endl;

	int res = solution(test);
	cout << res << endl;
	cout << "test 1,2,1" << endl;
	test = {1,2,1};
	res = solution(test);
	cout << res << endl;
	test = {1,2,1,0};
	res = solution(test);
	cout << res << endl;
	cout << "test 1 1 2 0" << endl; 
	test = {1,1,2,0};
	res = solution(test);
	cout << res << endl;
	cout << "test 1 1 2 0 1" << endl; 
	test = {1,1,2,0, 1};
	res = solution(test);
	cout << res << endl;
	cout << "test 1 1 2 0 1" << endl; 
	test = {1,1,2,0, 1};
	res = solution(test);
	cout << res << endl;
	cout << "test 1 2 1 2 1" << endl; 
	test = {1,2,1,2,1};
	res = solution(test);
	cout << res << endl;
	cout << "test 1 2 1 2 1 0" << endl; 
	test = {1,2,1,2,1,0};
	res = solution(test);
	cout << res << endl;
	test = {0, 1, 0, 0, 1, 0, 0, 1, 0};
	cout << "test = {0, 1, 0, 0, 1, 0, 0, 1, 0}" << endl;
	res = solution(test);
	cout << res << endl;
	cout << "test [1, 3, 2, 1]" << endl;
	test = {1, 3, 2, 1};
	res = solution(test);
	cout << "res=" << res << endl;


	return 0;
}

