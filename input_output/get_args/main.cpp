#include<iostream>
#include<vector>
#include "get_args.h"
using namespace std;
int main(int argc, char*argv[]) {
	vector<double> res = getCommandLineArgs<double>(argc,argv);
	show(res);
}
