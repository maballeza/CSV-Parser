#include "Manager.h"

int Manager::Determine(Routine r, std::pair<int, int>* interval) {
    int choice = 1;
    if (r == Routine::Choice) {
        std::wcout << L"Print options are (1) Complete List (2) Average"
            << std::endl << L"\tChoice: ";
        std::wcin >> choice;
        return choice;
    }
    else if (r == Routine::Interval) {
        std::wcout << std::endl << L"\tStarting index:\t";
        std::wcin >> interval->first;
        std::wcout << L"\tEnding index:\t";
        std::wcin >> interval->second;
        std::wcout << std::endl << std::endl;
        return choice;
    }
}

void Manager::Print(Routine r, Analysis::University&& uni) {
    if (r == Routine::Intro) {
        std::wcout << L"Project: Algorithms - Universities" 
                    << std::endl << std::endl;
    }
    else if (r == Routine::Table) {
        std::wofstream stream{ path };
        Table table;
        if (stream.is_open())
        {
            table.Print(stream, uni);
            stream.close();
        }
    }
}