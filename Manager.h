#pragma once
#include <iostream>
#include "Table.h"
#include "University.h"

enum class Routine { Intro, Choice, Interval, Table };

class Manager {
public:
    /**
    * Determines a course of action and returns either the user input
    * or the default value which indicates a continuation of the loop.
    *
    * @param r
    *   A Choice or Interval routine.
    * @param interval
    *   The inclusive range of values to evaluate over.
    */
    static int Determine(Routine r, std::pair<int, int>* interval = nullptr);

    /**
    * Prints Intro and Table routines.
    * 
    * @param r
    *   An Intro or Table routine.
    * @param uni
    *   Used with the Table routine to print a summary,
    *   defaulting to the entire list.
    */
    static void Print(Routine r, Analysis::University&& uni = {});

private:
    static inline std::wstring path{ L"..\\Data\\Res.txt" };
};