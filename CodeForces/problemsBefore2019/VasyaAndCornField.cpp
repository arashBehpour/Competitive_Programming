#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	double n, d; // coordinates of the grassfield
	int m; // number Of grasshoppers
	double x, y; // coordinate of the grass hopper as it is being read one by one

	cin >> n >> d;
	// Create border
	unordered_map<string, bool> myBorderMap; // If I wanted to use a std::pair<> as my key then i would need to create a hash function or use Boost library

	// 4 points that create the rectangle field
	double x1, y1; 
	x1 = 0; y1 = d; // (0,d) aka point 1
	double x2, y2;
	x2 = d; y2 = 0; // (d,0) aka point 2
	double x3, y3;
	x3 = n; y3 = n - d; // (n, n-d) aka point 3
	double x4, y4;
	x4 = n - d; y4 = n; // (n - d, n) aka point 4

	// Find the slopes and y-intercepts of the 4 lines that are created by the 4 points
	double m1 = (y4 - y1) / (x4 - x1); // point 1 to point 4; Upper Limit
	double b1 = y1 - (m1*x1);// chose point 1 to use as x and y for b, in equation y = mx + b

	double m2 = (y3 - y2) / (x3 - x2); // point 2 to point 3; Lower Limit
	double b2 = y2 - (m2*x2); // chose point 2 to use as x and y for b

	double m3 = (y2 - y1) / (x2 - x1); // point 1 to point 2; Lower Limit
	double b3 = y1 - (m3*x1); // chose point 1 to use as x and y for b

	double m4 = (y3 - y4) / (x3 - x4);// point 4 to point 3; Upper Limit
	double b4 = y4 - (m4*x4);//chose point 4 to use as x and y for b


	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		
		bool isGrasshopperOnField = true;
		if ((x > n) || (y > n)) {
			isGrasshopperOnField = false;
			cout << "NO" << endl;
		}
		else {
			// plug x & y and find corresponding upper/lower and right/left limit see if the inputs are between/equal those values
			double fy_a = (m1*x) + b1; // upper limit
			//cout << "fy_a: " << fy_a << endl;

			double fy_b = (m2*x) + b2; // lower limit
			//cout << "fy_b: " << fy_b << endl;

			double fy_c = (m3*x) + b3; // lower
			//cout << "fy_c: " << fy_c << endl;

			double fy_d = (m4*x) + b4; // upper
			//cout << "fy_d: " << fy_d << endl;


			if ( (y <= fy_a) && (y >= fy_b) && (y >= fy_c) && (y <= fy_d) ) {
				cout << "YES" << endl;
			}
			else {
				isGrasshopperOnField = false;
				cout << "NO" << endl;
			}
		}
		
		//string newCoord;
		//newCoord.append(to_string( (long long)x )); //  The long long typecasting is because codeforces does not support C++ 2011
		//newCoord.append(to_string( (long long)y ));

		//unordered_map<string, bool>::const_iterator got = myBorderMap.find(newCoord);

		//if (got == myBorderMap.end())
		//	cout << "NO" << endl;
		//else
		//	cout << "YES" << endl;


		//myBorderMap.emplace(std::pair<string,bool> (borderCoord, true)); // The pair<string,bool> is because codeforces does not support C++ 2011
	}

}