#include "roman.h"
std::vector<std::pair<unsigned int, char const*>> roman {
		{ 1000, "M" },{ 900, "CM" }, { 500, "D" },{ 400, "CD" },
			{ 100, "C" },{ 90, "XC" }, { 50, "L" },{ 40, "XL" },
			{ 10, "X" },{ 9, "IX" }, { 5, "V" },{ 4, "IV" }, { 1, "I" }};

std::map<std::string,unsigned int> mp2 = {{"CM",900}, {"CD",400},{"XC",90},{"XL",40},{"IX",9},{"IV",4}};


std::map<std::string,unsigned int> mp1 = {{"M",1000}, {"D",500},{"C",100},{"L",50},{"X",10},{"V",5},{"I",1}};


std::string to_roman(unsigned int value)
{
	std::string result;
	for (auto const & kvp : roman) {
		while (value >= kvp.first) {
			result += kvp.second;
			value -= kvp.first;
		}
	}
	return result;
}

unsigned int from_roman(const std::string& in) {
	using namespace std;
	std::string temp(in);
	unsigned int res=0;
	while(temp.length() > 0) {
		if(temp.length() > 1 && (mp1[std::string(1,temp[0])] < mp1[std::string(1,temp[1])])) {
			//special case
			std::string v = temp.substr(0,2);
			res+= mp2[v];
			temp = temp.substr(2);
		}else {
			res+=mp1[std::string(1,temp[0])];
			temp = temp.substr(1);
		}

	}
	return res;
}


