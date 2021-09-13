#include "Manager.hpp"
#include "Analysis.hpp"
#include "Parser.hpp"
#include <string>
#include <utility>

std::wstring dataPath { L"In\\cwurData.csv" };

enum Status { Exit, Proceed, Calculate };

/**
* This simple loop provides the ability to choose which type 
* of calculation to perform, the results of which are printed
* to file "Res.txt" in the "Out" directory.
*/
int main()
{
	Parser par;
	par.ParseData(dataPath);
	
	Manager::Print(Routine::Intro);

	int input = 1;
	while (input) {
		std::pair<int, int> interval { 0, 9 };
		input = Manager::Determine(Routine::Choice);
		
		Analysis::University results;
		switch (input) {
		case Status::Exit: {
			break;
		}
		case Status::Calculate: { // Evaluates an average at the user's discretion.
			input = Manager::Determine(Routine::Interval, &interval);
			results = Analysis::Average(interval);
			break;
		}
		default: { // Prints the entire list.
			input = 1;
		}}
		Manager::Print(Routine::Table, std::move(results));
	}
	
	return 0;
}