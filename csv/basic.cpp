#include <iostream>
#include <vector>
#include<string>
#include<fstream>

class CSV_Writer 
{
	public:
		using VS = std::vector<std::string>;
		CSV_Writer(std::string&& csvFilePathAndName, VS&& csvHeadings,bool firstColumnEmpty=true); 
		~CSV_Writer();
		//we assume that the data type has been converted to string
		void AddData(std::string&& data);
		void Close();
	private:
		size_t m_numColumns;
		size_t m_pos; // current column position
		bool m_firstColEmpty;
		std::ofstream m_fileout;


};

CSV_Writer::CSV_Writer(std::string&& outputCSVFilePathName, VS&& csvHeadings,bool firstColumnEmpty):
	m_numColumns(csvHeadings.size()),m_pos(0),m_firstColEmpty(firstColumnEmpty),
	m_fileout(outputCSVFilePathName,std::ios::out | std::ios::trunc)
{
	if (!m_fileout.is_open())
		throw std::runtime_error("Cannot open CSV file for writing");
	if (firstColumnEmpty)
	{
		m_fileout << ",";
	}
	//add the headings
	for(const auto& heading : csvHeadings)
	{
		if(m_pos == (m_numColumns-1))
			m_fileout << heading;
		else
			m_fileout << heading <<",";
		m_pos = (m_pos+1) % m_numColumns; 
	}
	m_fileout << std::endl;
}
CSV_Writer::~CSV_Writer()
{
	std::cout << "~CSV_Writer() " << std::endl;
	if (m_fileout.is_open())
	{

		std::cout << "~CSV_Writer() open now closing " << std::endl;
		m_fileout.close();
	}
}

//can be explictly closed or via destructor
void CSV_Writer::Close()
{

	if (m_fileout.is_open())
		m_fileout.close();
}

void CSV_Writer::AddData(std::string&& data)
{
	if((m_pos % m_numColumns) == (m_numColumns-1))
	{
		//last column, start new line
		m_fileout << data << std::endl;
	}
	else
	{
		if(m_firstColEmpty && m_pos == 0)
		{
			m_fileout << "," << data << ",";
		}
		else
		{
			m_fileout << data <<",";
		}
	}
	//update column position
	m_pos = (m_pos+1) % m_numColumns; 
}



int main(int argc, char** argv)
{
	CSV_Writer csv("temp.csv",{"Andy","Rob","John","Tom","Fred"});
	csv.AddData("1.1");
	csv.AddData("2.1");
	csv.AddData("3.1");
	csv.AddData("4.1");
	csv.AddData("5.1");
	csv.AddData("6.1");
	csv.AddData("7.1");
	csv.Close();

	return 0;

}
