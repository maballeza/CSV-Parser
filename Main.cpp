#include "Parser.h"
#include "Table.h"
#include "Analysis.h"

int main()
{
	Parser par;
	par.Parse(L".\\Data\\cwurData.csv");

	Analysis::University Average = Analysis::CalculateAverage(0, 9); // Averages first 9 list items.
	par.Print(L".\\Data\\Res.txt"/*, Average*/);  // Prints complete list or average.
	
	return 0;
}