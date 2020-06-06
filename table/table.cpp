#include <iostream>
#include<vector>
#include<numeric>
#include<string>
#include<algorithm>

using namespace std;

using MatrixS = std::vector<std::vector<std::string>>;
using RowS = std::vector<std::string>;
using RowI = std::vector<size_t>;

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
//compare current row widths with the current widths, updating it if necessary to get max
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
RowI maxWidths(const vector<string>& header, const MatrixS& rows)
{
	vector<size_t> acc = lengths(header);
	for(const auto& row : rows)
	{
		acc = getMax(acc,row);
	}
	return acc;

}

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

	template<typename T>
void print(const T& container)
{
	for(const auto& v : container)
	{
		cout << v << " ";
	}
	cout << "\n";
}
int main(int argc, char** argv)
{
	MatrixS rows = {{"Lisp","John Mac","1958"},
		{"C","Dennis Ritch", "1969"},
		{"ML","Robin Milner","1973"},
		{"Ocaml","Xavier Leroy","1996"}};
	vector<string> header = {"language","architect","first release"};

	vector<size_t> widths = maxWidths(header,rows);
	print(widths);
	//	print(lengths(header));
	string rend = renderSeparator(widths);
	cout << rend << endl;



	return 0;

}
