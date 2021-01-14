#pragma once

#include "University.h"
#include <vector>
#include <algorithm>
#include <fstream>

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
