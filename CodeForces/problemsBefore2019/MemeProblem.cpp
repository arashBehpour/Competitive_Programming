#include <iostream>
#include <iomanip> // std::setprecision

using namespace std;

// Meme Problem (Binary Search)
// Given d
// Eqn1: a + b = d 
// Eqn2: a * b = d
// relation using Eqn2 -> b = d/a
// chose a to be the midpoint from low and high --> a = (low + high)/2
// Then plug this (a) into the relationship derived: b = d/a 
// Then I have an (a) and (b) to use and see if its close to (d); by plugging back into Eqn1
// if the value calculated is larger than d, then do a binary search on left half and
// if the value calculated is smaller than d, then do a binary search on right half 
int main() {
	int numOfcases;

	cin >> numOfcases;

	double d;
	double low, high;
	double minAccuracy = 1e-7;
	for (int i = 0; i < numOfcases; i++) {
		cin >> d;
		
		low = 0; // will be positive integers so lowest possible value is 0
		high = d; // max needs to be d because if not then a + b > d 

		double a, b;
		int numOfMaxIterations = 0; // Do not want to get stuck continiously dividing
		bool hasAnswer = false;
		while (high >= low && numOfMaxIterations < 60) {
			a = (high + low) / 2; // midpoint of low and high = a
			if (a != 0)
				b = d / a; // assign b after I guessed an answer for a
			else
				b = 0; // avoid divide by 0 case

			if (abs(a + b - d) <= minAccuracy) { // expression just needs to be close to zero
				cout << fixed;
				cout << setprecision(9);
				if (a > b)
					cout << "Y " << a << " " << b << endl;
				else
					cout << "Y " << b << " " << a << endl;
				hasAnswer = true;
				break;
			}
			else if (a + b > d) { // go left
				high = (high + low) / 2; // For int must be (high + low)/2 + 1;
			}
			else { // (a + b < d) // go right
				low = (high + low) / 2;
			}
			numOfMaxIterations++;
		}
		
		if (!hasAnswer)
			cout << "N" << endl;
	}
}