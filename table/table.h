#pragma once

#include<vector>
#include<numeric>
#include<string>
#include<algorithm>

namespace UTILS {

		using MatrixS = std::vector<std::vector<std::string>>;

	//gets lengths of each string
	std::vector<size_t> lengths(const std::vector<std::string>& row);

	//compare current col widths, updating if necessary to get max col width 
	std::vector<size_t> getMax(const std::vector<size_t>& currentMax,const std::vector<std::string>& row);

	//get the max widths of each column
	std::vector<size_t> maxWidths(const std::vector<std::string>& header, const MatrixS& rows);

	//create a seperator between the table header and table rows
	std::string renderSeparator(const std::vector<size_t>& widths);

	//pads each columns item with appropriate number of spaces
	std::string pad(const std::string& str, size_t length);

	//create each table row
	std::string renderRow(std::vector<std::string>& row , std::vector<size_t>& widths);

	//render the table
	std::string renderTable(std::vector<std::string>& header, const MatrixS& rows);
}
