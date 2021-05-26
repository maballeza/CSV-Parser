#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "University.h"

class Table
{
public:
	
	void BuildTable(std::wstring);
	void BuildItem(int, std::wstring);

	void UpdateList();	// Adds new items to the list.
	void Print(std::wostream&, const Analysis::University uni = {});

	/**
	* Accessor methods.
	*/
	std::vector<Analysis::University>& List();
	std::vector<std::wstring>& Columns();

private:
	static std::vector<Analysis::University> list;
	static std::vector<std::wstring> cols;
	static Analysis::University item;
};