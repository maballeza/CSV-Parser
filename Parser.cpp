#include "Parser.h"

void Parser::Parse(const std::wstring path)
{
	Table table;
	stream.open(path);
	if (stream.is_open())
	{
		while (getline(stream, buffer, L'\n'))
		{
			bool isHeader = (buffer.size() > buffer.find(L'_')) ? true : false;

			size_t begin = 0, end = 0, col = 0;
			while (end < buffer.size())
			{
				// Find next value, accounting for last value (without a trailing comma).
				end = buffer.find(L',', begin);
				std::wstring value{ buffer, begin, (end > buffer.size() ? buffer.size() - begin : end - begin) };
				if (isHeader)  // Header: Remove "_" characters and capitalize titles, "of" being an exception.
				{
					auto p = value.begin();
					std::replace(p, value.end(), L'_', L' ');
					do
					{
						*p = toupper(*p);
						p = std::adjacent_find(p, --value.end(), [](wchar_t x, wchar_t y) { return (x == L' ') && (y != L'o'); });
					} while (++p != value.end());

					table.BuildTable(value);
				}
				else  // Values: Ignore commas within strings.
				{
					if (!value.empty() && value.front() == L'"' && value.back() != L'"')
					{
						begin = end;
						end = buffer.find(L',', ++end);
						value.append(buffer, begin, end - begin);
					}

					table.BuildItem(col++, value);
				}
				begin = end + 1;
			}
			if (!isHeader)
			{
				table.UpdateList();
			}
		}
		stream.close();
	}
}