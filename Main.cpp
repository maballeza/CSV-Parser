#include "Manager.h"
#include "Analysis.h"
#include "Parser.h"

static std::wstring dataPath{ L"..\\Data\\cwurData.csv" };

/**
* This simple loop parses through the list of top universities
* and cycles through the main loop providing options for printing summaries
* to the external file "Res.txt" in the "Data" directory.
* 
* Please build in Release mode using C++17.
*/
int main(int argc, char* argv[])
{
	Parser par;
	par.ParseData(dataPath);
	
	Manager::Print(Routine::Intro);

	int input = 1;
	while (input) {
		std::pair<int, int> interval{ 0, 9 };
		input = Manager::Determine(Routine::Choice);
		
		Analysis::University results;
		if (input == 0) { // Exits.
			break;
		}
		else if (input == 2) { // Evaluates an average at the user's discretion.
			input = Manager::Determine(Routine::Interval, &interval);
			results = Analysis::Average(interval);
		}
		else { // Prints the entire list by default.
			input = 1;
		}
		Manager::Print(Routine::Table, std::move(results));
	}
	
	return 0;
}