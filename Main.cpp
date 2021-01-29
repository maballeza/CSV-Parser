#include "Parser.h"
#include "Table.h"
#include "Analysis.h"

int main()
{
	Parser par;
	par.ParseData(L".\\Data\\cwurData.csv");

	Analysis::University Average1 = Analysis::CalculateAverage(0, 9);
	//par.PrintData(L".\\Data\\Res.txt", Average1);

	return 0;
}


//	ACT, R