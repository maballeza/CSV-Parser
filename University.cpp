#include "University.h"
#include <algorithm>
#include <utility>

namespace Analysis
{

	University::University() : 
		Rank{ 0, 0 }, Quality{ 0, 0 }, Institution{}, Country{}, 
		AlumniEmployment(0), Publications(0), Citations(0), Patents(0), Influence(0), BroadImpact(0), Score(0), Year(0)
	{
	}

	University::University(const University& uni) : 
		Rank{ uni.Rank }, Quality{ uni.Quality }, Institution{ uni.Institution }, Country{ uni.Country },
		AlumniEmployment(uni.AlumniEmployment), Publications(uni.Publications), Citations(uni.Citations), Patents(uni.Patents), Influence(uni.Influence), BroadImpact(uni.BroadImpact), Score(uni.Score), Year(uni.Year)
	{
	}

	University::University(University&& uni) noexcept : 
		Rank{ uni.Rank }, Quality{ uni.Quality }, Institution{ uni.Institution }, Country{ uni.Country },
		AlumniEmployment(uni.AlumniEmployment), Publications(uni.Publications), Citations(uni.Citations), Patents(uni.Patents), Influence(uni.Influence), BroadImpact(uni.BroadImpact), Score(uni.Score), Year(uni.Year)
	{
		uni.Rank = { 0, 0 };
		uni.Quality = { 0, 0 };
		uni.Institution = L"";
		uni.Country = L"";
		uni.AlumniEmployment = 0;
		uni.Publications = 0;
		uni.Citations = 0;
		uni.Patents = 0;
		uni.Influence = 0;
		uni.BroadImpact = 0;
		uni.Score = 0;
		uni.Year = 0;
	}

	University& University::operator=(const University& rUni)
	{
		Rank.World = rUni.Rank.World;
		Institution = L"";
		Country = L"";
		Rank.National = rUni.Rank.National;
		Quality.Education = rUni.Quality.Education;
		AlumniEmployment = rUni.AlumniEmployment;
		Quality.Faculty = rUni.Quality.Faculty;
		Publications = rUni.Publications;
		Influence = rUni.Influence;
		Citations = rUni.Citations;
		BroadImpact = rUni.BroadImpact;
		Patents = rUni.Patents;
		Score = rUni.Score;
		Year = rUni.Year;
		return *this;
	}

	University& University::operator=(University&& rUni) noexcept
	{
		Rank.World = rUni.Rank.World;
		Institution = L"";
		Country = L"";
		Rank.National = rUni.Rank.National;
		Quality.Education = rUni.Quality.Education;
		AlumniEmployment = rUni.AlumniEmployment;
		Quality.Faculty = rUni.Quality.Faculty;
		Publications = rUni.Publications;
		Influence = rUni.Influence;
		Citations = rUni.Citations;
		BroadImpact = rUni.BroadImpact;
		Patents = rUni.Patents;
		Score = rUni.Score;
		Year = rUni.Year;
		return *this;
	}

	University& University::operator+=(const University& rUni)
	{
		Rank.World += rUni.Rank.World;
		Institution = L"";
		Country = L"";
		Rank.National += rUni.Rank.National;
		Quality.Education += rUni.Quality.Education;
		AlumniEmployment += rUni.AlumniEmployment;
		Quality.Faculty += rUni.Quality.Faculty;
		Publications += rUni.Publications;
		Influence += rUni.Influence;
		Citations += rUni.Citations;
		BroadImpact += rUni.BroadImpact;
		Patents += rUni.Patents;
		Score += rUni.Score;
		Year += rUni.Year;
		return *this;
	}

	University& University::operator/=(int val)
	{
		Rank.World /= val;
		Institution = L"";
		Country = L"";
		Rank.National /= val;
		Quality.Education /= val;
		AlumniEmployment /= val;
		Quality.Faculty /= val;
		Publications /= val;
		Influence /= val;
		Citations /= val;
		BroadImpact /= val;
		Patents /= val;
		Score /= val;
		Year /= val;
		return *this;
	}

	void University::AssignMember(std::wstring data, int item)
	{
		{
			if (data.empty()) data = L"-1";
			if (std::none_of(data.begin(), data.end(), [](wchar_t x) { return isalpha(x); }))
			{
				if (item == 12)
				{
					Score = stof(data);
				}
				else
				{
					int i = stoi(data);
					if (item == 0) Rank.World = i;
					if (item == 3) Rank.National = i;
					if (item == 4) Quality.Education = i;
					if (item == 5) AlumniEmployment = i;
					if (item == 6) Quality.Faculty = i;
					if (item == 7) Publications = i;
					if (item == 8) Influence = i;
					if (item == 9) Citations = i;
					if (item == 10) BroadImpact = i;
					if (item == 11) Patents = i;
					if (item == 13) Year = i;
				}
			}
			else
			{
				if (item == 1) Institution = data;
				if (item == 2) Country = data;
			}
		}
	}

	float University::RetrieveMember(int item) const
	{
		if (item == 1 || item == 2) {	// wstring values.
			return -1;
		}
		if (item == 0) return Rank.World;
		if (item == 3) return Rank.National;
		if (item == 4) return Quality.Education;
		if (item == 5) return AlumniEmployment;
		if (item == 6) return Quality.Faculty;
		if (item == 7) return Publications;
		if (item == 8) return Influence;
		if (item == 9) return Citations;
		if (item == 10) return BroadImpact;
		if (item == 11) return Patents;
		if (item == 12) return Score;
		if (item == 13) return Year;
		else { return -1; }
	}

	int University::RetrieveIndex() const
	{
		return static_cast<int>(Rank.World);
	}

	std::map<int, std::wstring> University::map{};

	University CalculateAverage(const std::vector<University>& cont, int start, int total)
	{
		University ret{};
		int end = start + total - 1;
		if ((0 <= start && end < cont.size()) && !cont.empty())
		{
			int count = 0;
			for (const auto& item : cont)
			{
				int r = item.RetrieveIndex();
				if (start <= r && r <= end)
				{
					ret += item;
					count++;
				}
			}
			ret /= count;
		}
		return ret;
	}

} // namespace Analysis