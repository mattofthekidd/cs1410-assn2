#include "Timer.hpp"

Timer::Timer() :
	m_time(0)
{

}

void Timer::startTimer() {
	m_start = timer::now();
}

void Timer::endTimer() {
	m_end = timer::now();
}


double Timer::elapsedTime(Timer& obj) {
	obj.m_time = obj.m_end - obj.m_start;
	return obj.m_time.count();
}
