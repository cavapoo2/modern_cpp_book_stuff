#include "roman.h"
#include "get_args.h"
using namespace std;
int main(int argc, char*argv[]) {
	vector<int> a = getCommandLineArgs<int>(argc,argv);
	for(auto &v: a) {
		 std::string r = to_roman(v);
		 cout << v << " is " << r << endl;	
		 cout << r << " is " << from_roman(r) << endl;
	}
	return 0;

}

