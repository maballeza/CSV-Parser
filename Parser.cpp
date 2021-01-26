#include "Parser.h"

std::vector<Analysis::University> Parser::ParseData(const std::wstring path)
{
	stream.open(path, std::ios_base::in);

	std::vector<Analysis::University> list;
	while (getline(stream, buffer, L'\n'))
	{
		Analysis::University uni;
		bool isHeader = (buffer.size() > buffer.find(L'_')) ? true : false;
		
		size_t begin = 0, end = 0, col = 0;
		while (end < buffer.size())
		{
			// Find next value, accounting for last value (without a trailing comma).
			end = buffer.find(L',', begin);
			std::wstring value{ buffer, begin, (end > buffer.size() ? buffer.size() - begin : end - begin) };
			if (isHeader)	// Header: Remove "_" characters and capitalize titles, "of" being an exception.
			{
				auto p = value.begin();
				std::replace(p, value.end(), L'_', L' ');
				do
				{
					*p = toupper(*p);
					p = std::adjacent_find(p, --value.end(), [](wchar_t x, wchar_t y) { return (x == L' ') && (y != L'o'); });
				} while (++p != value.end());

				Analysis::University::map.emplace(col++, value);
			}
			else			// Values: Ignore commas within strings.
			{
				if (!value.empty() && value.front() == L'"' && value.back() != L'"')
				{
					begin = end;
					end = buffer.find(L',', ++end);
					value.append(buffer, begin, end - begin);
				}
				uni.AssignMember(value, col++);
			}
			begin = end + 1;
		}
		if (!isHeader) list.emplace_back(uni);
	}

	stream.close();
	return list;
}

void Parser::PrintData(const std::wstring path, const Analysis::University res)
{
	stream.open(path, std::ios_base::out);

	if (stream.is_open())
	{
		for (const auto val : Analysis::University::map)
		{
			stream << val.second << "\t" << res.RetrieveMember(val.first) << std::endl;
		}
	}

	stream.close();
}
