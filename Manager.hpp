#pragma once
#include "University.hpp"
#include "Table.hpp"
#include <string>

enum class Routine { Intro, Choice, Interval, Table };

class Manager {
public:
    /**
    * Determines a course of action and returns either the user input
    * or the default value, indicating a continuation of the loop.
    *
    * @param r
    *   A Choice or Interval routine.
    * @param interval
    *   The zero-based inclusive range of values over which to evaluate.
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
    static inline std::wstring path { L"Out\\Res.txt" };
};