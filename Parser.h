#pragma once
#include "University.h"
#include <vector>
#include <algorithm>
#include <fstream>

// 
// Expectations:
// 1.	The row containing column titles (header) includes at least 
//		one entry containing a "_" separating multi-word titles.
//
// 2.	The index is located in the first column (not in the header).
// 

class Parser
{
public:
	Parser(std::wstring string) : stream{ string, std::ios_base::in } {}
	~Parser() {}

	void ParseData(std::vector<Analysis::University>& item);

private:
	std::wfstream stream;
	std::wstring buffer;
	std::map<int, std::wstring> header;

};
