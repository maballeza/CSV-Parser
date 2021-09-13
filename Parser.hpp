#pragma once
#include "Table.hpp"
#include <string>
#include <fstream>

class Parser {
public:
	/**
	* Expects .csv files with the following attributes:
	*	1. Headers containing at least one multi-worded entry using an underscore to separate words.
	*	2. Indices located in the first column (the header being the exception).
	*/
	void ParseData(const std::wstring& path);

	/**
	* Removes "_" characters and capitalizes initial letters, "of" being an exception.
	*/
	void ParseHeader(const std::wstring&);
	void ParseEntry(const std::wstring&);

private:
	std::wfstream stream {};
};