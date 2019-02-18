#include <string>
#include <sstream>
#include<algorithm>
#include <cctype>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tstringstream = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

	template <class Elem>
tstring<Elem> capitalize(tstring<Elem> const & text)
{
	tstringstream<Elem> result;

	bool newWord = true;
	for (auto const ch : text)
	{
		newWord = newWord || std::ispunct(ch) || std::isspace(ch);
		if (std::isalpha(ch))
		{
			if (newWord)
			{
				result << static_cast<Elem>(std::toupper(ch));
				newWord = false;
			}
			else
				result << static_cast<Elem>(std::tolower(ch));
		}
		else result << ch;
	}

	return result.str();
}

template <class Elem>
tstring<Elem> uppercase(tstring<Elem> const & text){
	tstringstream<Elem> result;
	for(auto const ch : text){
		if(std::isalpha(ch)) {
			result << static_cast<Elem>(std::toupper(ch));
		}
		else{
			result << ch;
		}
	}
	return result.str();
}
template <class Elem>
tstring<Elem> caseChange(tstring<Elem> const & text, bool upper=true){
	tstring<Elem> res(text);
	auto func = (upper==true) ?  ([](Elem e) { return std::toupper(e); }) : 
		([](Elem e) { return std::tolower(e); }) ;
	std::transform(res.begin(), res.end(), res.begin(), 
			func// correct
			);
	return res;
}


