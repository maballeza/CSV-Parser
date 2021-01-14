#include "University.h"
#include "Parser.h"

int main()
{
	Parser par(L".\\Data\\cwurData.csv");
	std::vector<Analysis::University> universities;
	par.ParseData(universities);

	Analysis::University Average1 = Analysis::CalculateAverage(universities, 0, 10);

	return 0;
}