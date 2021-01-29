#pragma once

#include "Table.h"
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
	Parser() = default;
	~Parser() = default;

	void ParseData(const std::wstring path);

private:
	std::wfstream stream{};
	std::wstring buffer{};
};
