#include "Manager.hpp"
#include "Table.hpp"
#include <iostream>

int Manager::Determine(Routine r, std::pair<int, int>* interval) {
    int choice = 1;
    switch (r) {
    case Routine::Choice: {
        std::wcout << L"Print options are (1) Complete List (2) Average\n"
                   << L"\tChoice: ";
        std::wcin >> choice;
        std::wcout << '\n';
        return choice;
    }
    case Routine::Interval: {
        std::wcout << L"\tStarting index:\t";
        std::wcin >> interval->first;
        std::wcout << L"\tEnding index:\t";
        std::wcin >> interval->second;
        std::wcout << "\n\n";
        return choice;
    }
    default:
        return 0;
    }
}

void Manager::Print(Routine r, Analysis::University&& uni) {
    switch (r) {
    case Routine::Intro: {
        std::wcout << L"Project: Algorithms - Universities\n\n";
        break;
    }
    case Routine::Table: {
        Table table;
        if (std::wofstream stream { path }) {
            table.Print(stream, uni);
        }
        break;
    }}
}