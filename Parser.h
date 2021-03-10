#pragma once
#include "Table.h"
#include <algorithm>
#include <string>
#include <fstream>

// Assumptions:
// 1.	The header row includes at least one entry using
//		"_" characters to separate multiple-word titles.
// 2.	The first column contains index values.
class Parser
{
public:
	Parser() = default;
	~Parser() = default;

	void Parse(const std::wstring path);
	void Print(const std::wstring path, const Analysis::University uni = {});

private:
	std::wfstream stream{};
	std::wstring buffer{};
};