#include "table.h"
namespace UTILS {

	using namespace std;

	//get the Length of each item in the string row
	vector<size_t> lengths(const vector<string>& row)
	{
		vector<size_t> res;
		auto getLength =[](const std::string& s) {
			return s.length();
		};
		std::transform(row.cbegin(),row.cend(),std::back_inserter(res), getLength);
		return res;

	}
	//compare current col widths, updating if necessary to get max col width 
	vector<size_t> getMax(const vector<size_t>& currentMax,const vector<string>& row)
	{
		vector<size_t> res;
		vector<size_t> rowi = lengths(row); //convert to integers
		auto maxv = [](const size_t a,const size_t r){
			return std::max(a,r);
		};
		std::transform(currentMax.cbegin(),currentMax.cend(),rowi.cbegin(),std::back_inserter(res),maxv);
		return res;
	}
	//get the max widths of each column
	vector<size_t> maxWidths(const vector<string>& header, const MatrixS& rows)
	{
		vector<size_t> acc = lengths(header);
		for(const auto& row : rows)
		{
			acc = getMax(acc,row);
		}
		return acc;

	}
	//create a seperator between the table header and table rows
	string renderSeparator(const vector<size_t>& widths)
	{
		auto rep = [](size_t w )
		{
			return std::string(w+2,'-');
		};
		vector<string> pieces;
		std::transform(widths.cbegin(),widths.cend(),std::back_inserter(pieces), rep);

		string part = std::accumulate(pieces.begin(), pieces.end(), string(),
				[](string &ss, string &s)
				{
				return ss.empty() ? s : ss + "+" + s;
				});

		return "|" + part + "|";

	}
	//pads each columns item with appropriate number of spaces
	string pad(const string& str, size_t length)
	{
		string res = " ";
		string endSpace(length - str.length() +1,' ');
		return res + str + endSpace;
	}

	//create each table row
	string renderRow(vector<string>& row , vector<size_t>& widths)
	{
		auto padded = [](const string& item, size_t w) {
			return  pad(item,w) + "|" ;
		};
		vector<string> str;
		std::transform(row.cbegin(),row.cend(),widths.cbegin(),back_inserter(str),padded);

		string part = std::accumulate(str.begin(), str.end(), string(),
				[](string &ss, string &s)
				{
				return ss.empty() ? s : ss + s;
				});

		return "|" + part ;

	}

	//render the table
	string renderTable(vector<string>& header, const MatrixS& rows)
	{
		vector<size_t> widths = maxWidths(header,rows);
		string res = renderRow(header,widths);
		res += "\n" + renderSeparator(widths) + "\n";
		for(vector<string> row : rows)
		{
			string rr = renderRow(row,widths);
			res += rr + "\n";
		}
		return res;

	}
}
