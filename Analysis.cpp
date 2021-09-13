#include "Analysis.hpp"
#include "Table.hpp"

Analysis::University Analysis::Average(std::pair<int, int>& range)
{
	Table table;
	Analysis::University ret;
	for (auto& names : table.Columns()) { 
		ret.BuildMembers(0, names, L"0");
	}

	auto [start, end] = range;
	int total = end - start + 1;
	if (0 <= start && end <= table.List().size() - 1) {
		while (start <= end) {
			ret += table.List().at(start++);
		}
		ret /= total;
		return ret;
	}
}