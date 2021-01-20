#pragma once
#include <string>
#include <map>
#include <vector>

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

		// Initial on-boarding of values.
		void AssignMember(std::wstring, int);									
		// Selective data retrieval (used in support of analytical methods).
		float RetrieveMember(int) const;
		int RetrieveIndex() const;

		static std::map<int, std::wstring> map;

	private:
		struct Rank
		{
			float World;
			float National;
		};

		struct Quality
		{
			float Education;
			float Faculty;
		};

		Rank Rank;
		std::wstring Institution;
		std::wstring Country;
		Quality Quality;
		float AlumniEmployment;
		float Publications;
		float Citations;
		float Patents;
		float Influence;
		float BroadImpact;
		float Score;
		float Year;
	};

	// Zero-based index.
	University CalculateAverage(const std::vector<University>&, int start, int total);

} // namespace Analysis