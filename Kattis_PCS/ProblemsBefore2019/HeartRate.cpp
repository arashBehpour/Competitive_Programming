#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;
/* Problem H */
int main() {
	int numOfCases;

	cin >> numOfCases;

	for (size_t i = 0; i < numOfCases; i++) {
		double b; // treat the integer as a double to ease the typecasting
		double p; //  b is beats in p seconds

		cin >> b >> p;
		
		double bpm = (60 * b) / p;
		double minActualbpm = 60 / (p / (b - 1)); // t_min = p / (b - 1) b/c Actualbpm = 60/t
		double maxActualbpm = 60 / (p / (b + 1)); // t_max = p / (b + 1)

		// round bpm, min/max actual bpm to 10^-4 which is the ten thousands place. BETTER TO MAKE THIS A FUNCTION AND SEND PARAMETERS 
		minActualbpm = ceil(minActualbpm * 10000) / 10000;
		maxActualbpm = ceil(maxActualbpm * 10000) / 10000;
		bpm = ceil(bpm * 10000) / 10000;


		cout << std::fixed << std::setprecision(4) << minActualbpm << " " << bpm << " " << maxActualbpm << endl;
	}

	//while (1) {}
}
