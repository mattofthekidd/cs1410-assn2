#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

#include "TestCases.hpp"

std::vector<int> createVector(int size) {
	std::vector<int> x;
	for (int i = 0; i < size; i++) {
		x.push_back(rand() % size);
	}
	return x;
}

SortStats bubbleSort(std::vector<int> &list) {
	SortStats report;
	bool swapped = true;
	int totalSwaps = 0;
	while (swapped) {
			swapped = false;
		for (unsigned int i = 0; i < list.size() - 1; i++) {
			report.compareCount = i;
			if (list.at(i) > list.at(i + 1)) {
				std::swap(list[i], list[i + 1]);
				totalSwaps++;
				swapped = true;
			}
		}
	}

	report.swapCount = totalSwaps;
	report.time = 0;
	return report;
}

SortStats selectionSort(std::vector<int> &list) {
	SortStats report;
	int minPos = 0;
	int totalSwaps = 0;
	report.compareCount = 0;
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
			totalSwaps++;
		}
	}
	report.swapCount = totalSwaps;
	report.time = 0;
	return report;
}

void print(const std::vector<int> &list) {
	std::cout << "Number of items\t\t: " << list.size() << std::endl;
	std::cout << "Bubble sort time\t: " << std::endl;
	std::cout << "Selection sort time :" << std::endl;
}

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

	//executeTest(testCaseCompare, bubbleSort, selectionSort, "Sort Compare Test");
}


int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	//runTestCases();

	//my tests
	for (int i = 100; i <= 1000; i += 100) {
		std::vector<int> aList = createVector(i);
		std::vector<int> bList(aList);
		
		//for (int l = 0; l < 10; l++) {
		//	std::cout << "aList: " << l << ", " << aList.at(l) << std::endl;
		//	std::cout << "bList: " << l << ", " << bList.at(l) << std::endl;
		//}

		selectionSort(aList);
		selectionSort(bList);
		std::cout << "selection\n";
		print(aList);
		print(bList);

		//for (int l = 0; l < 10; l++) {
		//	std::cout << "aList: " << l << ", " << aList.at(l) << std::endl;
		//	std::cout << "bList: " << l << ", " << bList.at(l) << std::endl;
		//}

		aList.erase(aList.begin(), aList.end());
		aList = createVector(i);
		bList = aList;
		std::cout << "bubble\n";
		print(aList);
		print(bList);
	}
	

	return 0;
}
