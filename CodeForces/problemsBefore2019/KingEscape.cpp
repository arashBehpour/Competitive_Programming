#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n; // n is size of the grid
	int ax, ay; // coordinates of alice's queen
	int bx, by; // coordinates of bob's king
	int cx, cy; // goal coordinates that bob needs to get too

	cin >> n;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;

	if ((bx < ax && ax < cx) || (cx < ax && ax < bx) || (by < ay && ay < cy) || (cy < ay && ay < by)) {
		cout << "NO" << endl;
	}
	else
		cout << "YES" << endl;



	// while(1){}
}