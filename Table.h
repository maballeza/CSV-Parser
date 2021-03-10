#pragma once
#include "University.h"
#include <string>
#include <vector>
#include <fstream>

class Table
{
public:
	Table() = default;
	~Table() = default;

	// Getter methods.
	std::vector<Analysis::University>& List();
	std::vector<std::wstring>& Columns();

	void BuildTable(std::wstring);
	void BuildItem(int, std::wstring);

	void UpdateList();  // Adds new items to the list.
	void Print(std::wostream&, const Analysis::University uni = {});

private:
	static std::vector<Analysis::University> list;
	static std::vector<std::wstring> cols;
	Analysis::University item;
};