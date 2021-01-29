#pragma once
#include "University.h"
#include <vector>

using au = Analysis::University;

class Table
{
public:
	Table() = default;
	~Table() = default;

	void BuildTable(std::wstring);
	void BuildItem(int, std::wstring);

	//void Print(std::wfstream&);

	void UpdateList();
	std::vector<au>& List();
	std::vector<std::wstring>& Columns();

private:
	static std::vector<au> list;
	static std::vector<std::wstring> cols;
	au entry;
};