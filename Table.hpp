#pragma once
#include "University.hpp"
#include <string>
#include <vector>
#include <fstream>

class Table {
public:
	void BuildTable(const std::wstring&);
	void BuildItem(int, std::wstring&);

	void UpdateList();	// Adds new items to the list.
	void Print(std::wostream&, const Analysis::University& uni = {});

	/**
	* Accessor methods.
	*/
	std::vector<Analysis::University>& List() const { return list; }
	std::vector<std::wstring>& Columns() const { return cols; }

private:
	static std::vector<Analysis::University> list;
	static std::vector<std::wstring> cols;
	static Analysis::University item;
};