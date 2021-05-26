#include "Parser.h"

void Parser::ParseData(const std::wstring path)
{
	// TODO: partition_copy -> pass single entry
	stream.open(path, std::ios_base::in);
	std::wstring buffer{};
	
	while (getline(stream, buffer, L'\n'))
	{
		bool isHeader = (buffer.size() > buffer.find(L'_')) ? true : false;
		
		if (isHeader)
		{
			ParseHeader(buffer);
		}
		else
		{
			ParseEntry(buffer);
		}
	}

	stream.close();
}

void Parser::ParseHeader(std::wstring buffer)
{
	// TODO: One of the replace_copy functions
	//		* Argument: iterator or single entry
	size_t begin = 0, end = 0, col = 0;
	Table table;
	while (end < buffer.size())
	{
		// Find next value, accounting for last value (without a trailing comma).
		end = buffer.find(L',', begin);
		std::wstring value{ buffer, begin, (end > buffer.size() ? buffer.size() - begin : end - begin) };

		auto p = value.begin();
		std::replace(p, value.end(), L'_', L' ');
		do
		{
			*p = toupper(*p);
			p = std::adjacent_find(p, --value.end(), [](wchar_t x, wchar_t y) { return (x == L' ') && (y != L'o'); });
		} while (++p != value.end());

		table.BuildTable(value);

		begin = end + 1;
	}
}

void Parser::ParseEntry(std::wstring buffer)
{
	size_t begin = 0, end = 0, col = 0;
	Table table;
	while (end < buffer.size())
	{
		// Find next value, accounting for last value (without a trailing comma).
		end = buffer.find(L',', begin);
		std::wstring value{ buffer, begin, (end > buffer.size() ? buffer.size() - begin : end - begin) };

		if (!value.empty() && value.front() == L'"' && value.back() != L'"')
		{
			begin = end;
			end = buffer.find(L',', ++end);
			value.append(buffer, begin, end - begin);
		}

		table.BuildItem(col++, value);
		
		begin = end + 1;
	}
	table.UpdateList();
}