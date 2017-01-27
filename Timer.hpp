#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>

// ------------------------------------------------------------------
//
// Class for handling the timer used by the sorting functions.
//
// ------------------------------------------------------------------
class Timer {
public:
	// ------------------------------------------------------------------
	//
	// My default constructor.
	// Initializes m_time to 0. I honestly don't know how to initialize start and end.
	//
	// ------------------------------------------------------------------
	Timer();

	// ------------------------------------------------------------------
	//
	// Sets the starting point for the timer.
	//
	// ------------------------------------------------------------------
	void startTimer();
	// ------------------------------------------------------------------
	//
	// Sets the ending point for the timer.
	//
	// ------------------------------------------------------------------
	void endTimer();
	// ------------------------------------------------------------------
	//
	// Subtracts m_end from m_start and saves it to m_time.
	// Then returns the count() of m_time as a double for the SortStats time variable.
	//
	// ------------------------------------------------------------------
	double elapsedTime(Timer& obj);

	// I was having a hard time reading the code so I used this to reduce clutter.
	// typedef <thing to be aliased> <alias name>
	typedef std::chrono::high_resolution_clock timer;

private:
	std::chrono::time_point<timer> m_start;
	std::chrono::time_point<timer> m_end;
	std::chrono::duration<double> m_time;
};


#endif //_TIMER_HPP_