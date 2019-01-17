#include<string_view>
#include<algorithm>
#include<cctype>
#include<numeric>
#include<iostream>
bool validate_isbn_10(std::string_view isbn)
{
	auto valid = false;
	if (isbn.size() == 10 &&
			std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
	{
		auto w = 10;
		auto sum = std::accumulate(
				std::begin(isbn), std::end(isbn), 0,
				[&w](int const total, char const c) {
				return total + w-- * (c - '0'); });
		valid = !(sum % 11);
		//std::cout << "sum=" << sum << std::endl;
	}
	return valid;
}

bool validate_isbn_13(std::string_view isbn)
{
	if (isbn.size() == 13 &&
			std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 13)
	{
		int m=1;	
		auto sum = std::accumulate(
				std::begin(isbn), std::prev(std::end(isbn)), 0,
				[&m](int const total, char const c) {
				int temp = m * (c - '0');
				m = (m ==1) ? 3 : 1;
				return total + temp;
				});
		int res = sum % 10;
		auto last = isbn.back();

		//std::cout << "sum13=" << sum << " res= " << res << " last =" << last <<  std::endl;
		if(res == 0) return true;
		else if((10 - res) == (last - '0')){
		 	return true;
		}
		else return false;
}
return false;
}

