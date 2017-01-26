#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>

// ------------------------------------------------------------------
//
// Struct for the chrono variables. Goal was to reduce the amount of code in main.cpp
// I previously had it in the sorting functions but wanted to experiment with using a struct.
// Used SortStats.cpp and SortStats.hpp as reference.
//
// ------------------------------------------------------------------
struct Timer {
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
	std::chrono::duration<double> time;
};

double totalTime(Timer& obj);

#endif //_TIMER_HPP_