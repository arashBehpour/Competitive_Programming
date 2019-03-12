#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

/* Problem D*/

static void performMovementInstr(int nThrows, int numOfStudents, int &locationOfEgg) {

	if (nThrows != 0 && (abs(nThrows) % numOfStudents != 0)) { // check if Daenerys calls out 0(n, -n, 2n, -2n, etc.) then location of the egg stays the same
		int movement = abs(nThrows) % numOfStudents;

		if (nThrows > 0) { // If the nThrows is positive we move clockwise in the array
			locationOfEgg = locationOfEgg + movement;
			if (locationOfEgg / (numOfStudents - 1) > 0) {
				locationOfEgg = (locationOfEgg % numOfStudents);
			}

		}
		else { // If the nThrows is negative we move clockwise in the array
			locationOfEgg = locationOfEgg - movement;
			if (locationOfEgg < 0) {
				locationOfEgg = numOfStudents - (abs(locationOfEgg) % numOfStudents);
			}
		}
	} // end of statment for movement of the egg
}


int main() {
	int numOfStudents;
	int numOfThrowCommands;
	vector<string> listOfThrowCommands; // Container containing all the throw commands

	
	string line1, line2;
	getline(cin, line1);
	getline(cin, line2);

	istringstream is(line1);
	istringstream is2(line2);
	string command;

	is >> numOfStudents >> numOfThrowCommands;

	while (is2 >> command) {
		listOfThrowCommands.push_back(command);
	}

	int locationOfEgg = 0; // This will be the index of the where the egg is. Initially with child 0
	stack<int> commandsStack; // This is going to record all the commands in order
	string prevCommand;

	for (int i = 0; i < listOfThrowCommands.size(); i++) {
		
		if (listOfThrowCommands[i] != "undo") {
			if (prevCommand != "undo") {
				int nThrows = stoi(listOfThrowCommands[i]); // PUT THIS ALL IN A FUNCTION AND WHEN I CALL UNDO CALL THIS AND DO THE OPPOSITE
				commandsStack.push(nThrows); // pushes the command on the stack so if there is an undo

				performMovementInstr(nThrows,numOfStudents, locationOfEgg);
			}
			else {
				prevCommand.clear();
				int numberOfUndos = stoi(listOfThrowCommands[i]);

				for (int j = 0; j < numberOfUndos; j++) {
					int nRevThrows = (commandsStack.top()) * -1;
					commandsStack.pop();

					performMovementInstr(nRevThrows, numOfStudents, locationOfEgg);
				}
			}

		} // end of moving 
		else { 
			prevCommand = "undo"; // by default
		} 

	}

	cout << locationOfEgg << endl;
	//while (1) {}
}