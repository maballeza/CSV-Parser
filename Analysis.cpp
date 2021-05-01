#include "Analysis.h"

namespace Analysis
{
	University Average(std::pair<int, int> range)
	{
		Table table;
		University ret;
		int start = range.first;
		int end = range.second;

		for (auto& names : table.Columns())
		{ 
			ret.BuildMembers(0, names, L"0");
		}

		int total = end - start + 1;
		if (0 <= start && end < table.List().size())
		{
			while (start <= end)
			{
				ret += table.List().at(start++);
			}
			ret /= total;
		}
		return ret;
	}
}