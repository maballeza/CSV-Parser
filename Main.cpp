#include "University.h"
#include "Parser.h"

int main()
{
	Parser par;
	std::vector<Analysis::University> universities = par.ParseData(L".\\Data\\cwurData.csv");

	Analysis::University Average1 = Analysis::CalculateAverage(universities, 0, 10);
	par.PrintData(L".\\Data\\Res.txt", Average1);

	return 0;
}