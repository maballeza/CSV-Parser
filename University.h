#pragma once
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

namespace Analysis
{
	class University
	{
	public:
		University();
		University(const University&);
		University(University&&) noexcept;
		~University() {};
		University& operator=(const University&);
		University& operator=(University&&) noexcept;

		University& operator+=(const University& rUni);
		University& operator/=(int val);

		void BuildMembers(int, std::wstring, std::wstring);

	private:
		std::vector<std::pair<std::wstring, float>> fmembers;
		std::vector<std::pair<std::wstring, std::wstring>> wsmembers;
	};
} // namespace Analysis