/**
*	Matthew Kidd
*	A00953448
**/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>

#include "TestCases.hpp"
#include "Timer.hpp"

std::vector<int> createVector(int size);
SortStats bubbleSort(std::vector<int>& list);
SortStats selectionSort(std::vector<int>& list);
void print(const std::vector<int>& list, const SortStats& reportBubble, const SortStats& reportSelection);

// ------------------------------------------------------------------
//
// Run the test cases to help verify the code is correct.
//
// ------------------------------------------------------------------
void runTestCases()
{
	executeTest(testCase1, bubbleSort, "Bubble Sort: 10 items");
	executeTest(testCase2, bubbleSort, "Bubble Sort: 500 items");
	executeTest(testCase3, bubbleSort, "Bubble Sort: 100 to 1000 items");

	executeTest(testCase1, selectionSort, "Selection Sort: 10 items");
	executeTest(testCase2, selectionSort, "Selection Sort: 500 items");
	executeTest(testCase3, selectionSort, "Selection Sort: 100 to 1000 items");

	executeTest(testCaseCompare, bubbleSort, selectionSort, "Sort Compare Test");
}


int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	//runTestCases();

	//my tests
	for (int i = 100; i <= 1000; i += 100) {
		std::vector<int> aList = createVector(i);
		std::vector<int> bList(aList);
		print(aList, bubbleSort(aList), selectionSort(bList));
	}

	return 0;
}

// ------------------------------------------------------------------
//
// Creates my vectors with random numbers in the range of the vector's size.
//
// ------------------------------------------------------------------
std::vector<int> createVector(int size) {
	std::vector<int> x;
	for (int i = 0; i < size; i++) {
		x.push_back(rand() % size);
	}
	return x;
}


// ------------------------------------------------------------------
//
// Bubble sort for vectors
// Returns the SortStats values: compareCount, swapCount, and time.
//
// ------------------------------------------------------------------
SortStats bubbleSort(std::vector<int>& list) {
	SortStats report;
	report.compareCount = 0;
	report.swapCount = 0;
	report.time = 0;
	Timer stopwatch;
	bool swapped = true;

	//
	// Grab the starting time
	stopwatch.start = std::chrono::high_resolution_clock::now();

	while (swapped) {
		swapped = false;
		for (unsigned int i = 0; i < list.size() - 1; i++) {
			report.compareCount++;
			if (list.at(i) > list.at(i + 1)) {
				std::swap(list[i], list[i + 1]);
				report.swapCount++;
				swapped = true;
			}
		}
	}

	//
	// Grab the ending time
	stopwatch.end = std::chrono::high_resolution_clock::now();
	//
	// Compute how long it took, then save that value to SortStats object.
	report.time = totalTime(stopwatch);

	return report;
}

// ------------------------------------------------------------------
//
// Selection sort for vectors
// Returns the SortStats values: compareCount, swapCount, and time.
//
// ------------------------------------------------------------------
SortStats selectionSort(std::vector<int>& list) {
	SortStats report;
	report.compareCount = 0;
	report.swapCount = 0;
	report.time = 0;
	typedef std::chrono::high_resolution_clock timer;
	Timer stopwatch;
	int minPos = 0;
	
	//
	// Grab the starting time
	stopwatch.start = timer::now();

	for (int start = 0; start < list.size() - 1; start++) {
		minPos = start;
		for (int scanPos = start + 1; scanPos < list.size(); scanPos++) {
			report.compareCount++;
			if (list.at(minPos) > list.at(scanPos)) {
				minPos = scanPos;
			}
		}
		if (minPos != start) {
			std::swap(list[minPos], list[start]);
			report.swapCount++;
		}
	}
	//
	// Grab the ending time
	stopwatch.end = std::chrono::high_resolution_clock::now();
	//
	// Compute how long it took, then save that value to SortStats object.
	report.time = totalTime(stopwatch);

	return report;
}

// ------------------------------------------------------------------
//
// Print function
// Displays the number of items in the vector and the time taken to sort them via bubble and selection sort methods.
//
// ------------------------------------------------------------------
void print(const std::vector<int>& list, const SortStats& reportBubble, const SortStats& reportSelection) {
	std::cout << "Number of items\t\t: " << list.size() << std::endl;
	std::cout << "Bubble sort time\t: " << reportBubble.time << std::endl;
	std::cout << "Selection sort time\t: " << reportSelection.time << std::endl << std::endl;
}

