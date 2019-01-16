#include "read_ints.h"

std::vector<int> readInts(std::istream& is,const std::string& terminator)
{
	using namespace std;
	vector<int> res;
	for(int i; is >> i;)
		res.push_back(i);

	if(is.eof())
		return res;

	if(is.fail()){
		is.clear();
		is.unget();
		std::string s;
		if(cin>>s && s==terminator)
			return res;
		cin.setstate(ios_base::failbit);
	}

	return res;
}

