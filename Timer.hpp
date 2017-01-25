#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>

struct Timer {
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
	std::chrono::duration<double> time;
};

double totalTime(Timer& obj);

#endif //_TIMER_HPP_