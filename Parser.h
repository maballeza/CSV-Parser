#pragma once

#include <algorithm>
#include <string>
#include <fstream>
#include "Table.h"


class Parser
{
public:
	/**
	* Expects  
	* 1. Headers to include at least one entry using an underscore to separate multi-word titles
	* 2. Indexes to be located in the first column--the exception being the header.
	*/
	void ParseData(const std::wstring path);

	/**
	* Removes "_" characters and capitalizes initial letters, "of" being an exception.
	*/
	void ParseHeader(std::wstring);
	void ParseEntry(std::wstring);

private:
	std::wfstream stream{};
};
