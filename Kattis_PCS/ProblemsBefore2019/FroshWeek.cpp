#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* Problem K*/
int main() {
	int numOfTasks, numOfQuietIntervals;
	cin >> numOfTasks >> numOfQuietIntervals;

	priority_queue<int> taskLengths; // Will use this as the opposite of a priority queue(minimum value on top)
	priority_queue<int> quietIntervalLengths; // I want to make sure the tasks with the minimum length time are completed first

	for (size_t i = 0; i < numOfTasks; i++) {
		int taskLength;
		cin >> taskLength;

		taskLengths.push(-1 * taskLength);
	}

	for (size_t i = 0; i < numOfQuietIntervals; i++) {
		int quietIntervalLength;
		cin >> quietIntervalLength;

		quietIntervalLengths.push(-1 * quietIntervalLength);
	}

	int maxNumOfTasksComplete = 0;
	
	while (quietIntervalLengths.size() != 0 && taskLengths.size() != 0) {
		int curTaskLength = -1 * taskLengths.top();
		int curQuietInterval = -1 * quietIntervalLengths.top();

		if (curTaskLength <= curQuietInterval) {
			taskLengths.pop();
			maxNumOfTasksComplete++;
		}
		quietIntervalLengths.pop();
	}

	cout << maxNumOfTasksComplete << endl;
	//while (1) {};
}