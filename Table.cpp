#include "Table.h"

std::vector<Analysis::University> Table::list{};
std::vector<std::wstring> Table::cols{};

void Table::BuildTable(std::wstring entry)
{
	cols.emplace_back(entry);
}

void Table::BuildItem(int index, std::wstring value)
{
	entry.BuildMembers(index, cols.at(index), value);
}

void Table::UpdateList()
{
	list.emplace_back(std::move(entry));
}

std::vector<au>& Table::List()
{
	return list;
}

std::vector<std::wstring>& Table::Columns()
{
	return cols;
}
