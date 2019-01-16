#include "lcm.h"
#include "get_args.h"
using namespace std;
int main(int argc, char*argv[]) {
	vector<int> a = getCommandLineArgs<int>(argc,argv);
	int res = lcmr(a.begin(), a.end());

	cout << res << endl;

	return 0;

}


