#include<iostream>
#include "read_ints.h"
using namespace std;
int main(int argc, char*argv[]) {

	vector<int> res =  readInts(cin,"stop");

	for(auto& v : res)
		cout << v << endl;


}
