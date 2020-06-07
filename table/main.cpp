#include <iostream>
#include "table.h"
using namespace std;
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
	UTILS::MatrixS rows = {{"Lisp","John Mac","1958"},
		{"C","Dennis Ritch", "1969"},
		{"ML","Robin Milner","1973"},
		{"Ocaml","Xavier Leroy","1996"}};
	vector<string> header = {"language","architect","first release"};

	string table = UTILS::renderTable(header,rows);
	cout << table << endl;

	return 0;

}
