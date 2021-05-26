#include "University.h"

namespace Analysis
{
	University::University() : 
		fmembers{}, wsmembers{}
	{
	}

	University::University(const University& uni) : 
		fmembers{ uni.fmembers }, wsmembers{ uni.wsmembers }
	{
	}

	University::University(University&& uni) noexcept : 
		fmembers{ uni.fmembers }, wsmembers{ uni.wsmembers }
	{
		uni.fmembers.clear();
		uni.wsmembers.clear();
	}

	University& University::operator=(University&& rUni) noexcept
	{
		fmembers = rUni.fmembers;
		wsmembers = rUni.wsmembers;
		return *this;
	}

	University& University::operator+=(const University& rUni)
	{
		auto it = rUni.fmembers.begin();
		for (auto& [name, val] : fmembers)
		{
			if (name == (*it).first)
			{
				val += (*it).second;
				it++;
			}
		}
		return *this;
	}

	University& University::operator/=(int val)
	{
		for (auto& entry : fmembers)
		{
			if (val > 0)
			{
				entry.second /= val;
			}
		}
		return *this;
	}

	std::wostream& operator<<(std::wostream& stream, const University uni)
	{
		for (auto& [name, val] : uni.wsmembers)
		{
			stream << name << L'\t' << val << L'\n';
		}
		for (auto& [name, val] : uni.fmembers)
		{
			stream << name << L'\t' << val << L'\n';
		}
		return stream;
	}

	void University::BuildMembers(int index, std::wstring name, std::wstring data)
	{
		if (data.empty()) data = L"-1";
		if (std::none_of(data.begin(), data.end(), [](wchar_t x) { return isalpha(x); }))
		{
			float f = stof(data);
			fmembers.emplace_back(std::make_pair(name, f));
		}
		else if (index == 1 || index == 2)
		{
			wsmembers.emplace_back(std::make_pair(name, data));
		}
	}

	bool University::Empty() const
	{
		return fmembers.empty() && wsmembers.empty();
	}

} // namespace Analysis