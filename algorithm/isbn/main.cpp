#include "get_args.h"
#include "isbn.hpp"
using namespace std;
int main(int argc, char*argv[]) {
	vector<string> a = getCommandLineArgs<string>(argc,argv);
	for(auto &v: a) {
		bool res = validate_isbn_10(string_view(v));
		cout << "res10=" << res << endl;
		bool res2 = validate_isbn_13(string_view(v));
		cout << "res13=" << res2 << endl;
	}
	return 0;

}

