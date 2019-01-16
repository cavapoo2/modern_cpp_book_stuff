#include "lcm.h"
#include "get_args.h"
using namespace std;
int main(int argc, char*argv[]) {
	vector<int> a = getCommandLineArgs<int>(argc,argv);
	int res = lcmr(a.begin(), a.end());

	cout << res << endl;

	cout << std::lcm(20,40) << endl; //here's the constexpr version as well

	return 0;

}


