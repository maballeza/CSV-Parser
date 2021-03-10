#include "Table.h"

std::vector<Analysis::University> Table::list{};
std::vector<std::wstring> Table::cols{};

std::vector<Analysis::University>& Table::List()
{
	return list;
}

std::vector<std::wstring>& Table::Columns()
{
	return cols;
}

void Table::BuildTable(std::wstring entry)
{
	cols.emplace_back(entry);
}

void Table::BuildItem(int index, std::wstring value)
{
	item.BuildMembers(index, cols.at(index), value);
}

void Table::UpdateList()
{
	list.emplace_back(std::move(item));
}

void Table::Print(std::wostream& stream, const Analysis::University uni)
{
	if (!uni.Empty())
	{
		stream << uni << L'\n';
	}
	else {
		for (auto& item : list) {
			stream << item << L'\n';
		}
	}
}