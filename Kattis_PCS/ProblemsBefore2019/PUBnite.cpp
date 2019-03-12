#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

/* Problem F*/
int main() {
	double xZone, yZone, dr_dtZone, rInitial, rFinal; // all CONSTANTS HERE
	double xAnthony, yAnthony, dr_dtAnthony; // xAnthony and yAnthony change to be closer to the circle each second

	cin >> xZone >> yZone >> dr_dtZone >> rInitial >> rFinal;
	cin >> xAnthony >> yAnthony >> dr_dtAnthony;

	double rZone;
	rZone = rInitial; // The radius of the zone in the beginning is rInitial

	double rAnthony; // This is the radius of anthony 
	double AnthonysDmgTaken;

	rAnthony = sqrt(pow((xAnthony - xZone), 2.0) + pow((yAnthony - yZone),2.0));

	if (rAnthony < rFinal ) { // Anthonys already inside the final safe zone
		AnthonysDmgTaken = 0;
	}
	else if (rAnthony > rZone && dr_dtAnthony > dr_dtZone) {// Anthonys outside of the safe zone but has a greater rate of speed than the speed of the zone
		double timeForAnthonyToReachZone = (rAnthony - rZone) / (dr_dtAnthony - dr_dtZone); // anthony reaches the zone before the zone hits the final radius where it stops
		double timeForAnthonyToReachFinal = (rAnthony - rFinal) / dr_dtAnthony; // zone has reached final radius before anthony is able to cross in it 
		
		if (timeForAnthonyToReachZone < timeForAnthonyToReachFinal)
			AnthonysDmgTaken = timeForAnthonyToReachZone;
		else
			AnthonysDmgTaken = timeForAnthonyToReachFinal;
	}
	else if (rAnthony > rZone && dr_dtAnthony <= dr_dtZone) {// Anthonys outside of the safe zone but has a slower/equal rate of speed compared to the speed of the zone
		double timeToReachFinal = (rAnthony - rFinal)/ dr_dtAnthony; // Anthony will not be able to reach the zone, which will result in him taking damage until he reaches final radius
		AnthonysDmgTaken = timeToReachFinal;
	}
	else if (rAnthony <= rZone && dr_dtAnthony >= dr_dtZone) { // Anthonys inside/on the zone but has a greater/equal rate of speed compared to the zones speed
		AnthonysDmgTaken = 0;
	}
	else if (rAnthony < rZone && dr_dtAnthony < dr_dtZone) { // Anthonys inside/on the zone but has a slower rate of speed compared to the zones speed
		double timeForZoneToReachAnthony = (rZone - rAnthony) / (dr_dtZone - dr_dtAnthony); 
		double timeForAnthonyToReachFinal = (rAnthony - rFinal) / dr_dtAnthony;
		
		if (timeForAnthonyToReachFinal < timeForZoneToReachAnthony) // Means anthony has made it to the inner safe zone before being hit by the storm(faster than him)
			AnthonysDmgTaken = 0;
		else
			AnthonysDmgTaken = timeForAnthonyToReachFinal - timeForZoneToReachAnthony;
	}

	cout << std::fixed << std::setprecision(6) << AnthonysDmgTaken << endl;
	//while (1) {};
}
