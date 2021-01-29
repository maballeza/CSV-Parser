#include "Analysis.h"

namespace Analysis
{
	University CalculateAverage(int start, int end)
	{
		Table table;
		University ret;
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