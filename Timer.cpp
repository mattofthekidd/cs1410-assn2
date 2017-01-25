#include "Timer.hpp"

double totalTime(Timer& obj) {
	obj.time = obj.end - obj.start;
	return obj.time.count();
}
