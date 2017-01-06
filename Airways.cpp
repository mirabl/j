/*
Problem Statement
Air traffic control requires that the routes of aircraft be restricted. We want to investigate the costs of requiring aircraft to fly only in a few directions. For example, we could require them to fly only north, east, south, or west.
It makes sense to distribute the allowable directions evenly. If we allow only n directions, one will be east and the others will be evenly distributed among all other possible directions. So if n is 3, the three directions are east, 30 degrees west of north, and 30 degrees west of south. Adjacent directions then differ by 120 degrees. Notice that if a direction is legal the opposite direction may not necessarily be legal.

The following picture shows a minimum way to fly to a destination which is 5 east and 3 north of the starting point when n is 8. The 8 allowable directions are shown in blue. By flying a distance of 3*sqrt(2) northeast, and then 2 east (or 2 east, and then 3*sqrt(2) northeast) we can get to our destination by travelling a total distance of 3*sqrt(2) + 2. Notice that for any n and destination the minimal distance can be achieved using no more than two directions.



Create a class Airways that contains a method distance that is given n (the number of legal directions), east (the distance eastward to our destination), and north (the distance northward to our destination). It returns the minimum distance we will have to fly to get to our destination under these requirements.

Definition
Class: Airways
Method: distance
Parameters: int, int, int
Returns: double
Method signature: double distance(int n, int east, int north)
(be sure your method is public)
Limits
Time limit (s): 840.000
Memory limit (MB): 64
Notes
- The returned value must be accurate to within a relative or absolute value of 1E-9.
Constraints
- n will be between 3 and 40, inclusive.
- east and north will be between -5000 and 5000, inclusive.
Examples
0)
3
-219
0
Returns: 437.99999999999994
We want to go 219 due west. One way to do that is to fly 219 in the direction that is 30 degrees west of due south, then fly 219 in the direction 30 degrees west of due north. Our path will form 2 sides of an equilateral triangle.
1)
3
171
0
Returns: 171.0
We want to go due east, and that is always an allowed direction.
2)
4
233
3111
Returns: 3344.0000000000005
We can go 3111 due north and then 233 east since these are legal directions when n is 4.
3)
14
-3840
-1768
Returns: 4243.534462721784
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Airways {
public:
	bool solve(double a, double c, double b, double d, double A, double B, double *X, double *Y) {
		if (b*c - a*d == 0 || a == 0 || c == 0) {
			return false;
		}
		*Y =  (c * A - c * B) / (b * c - a * d);
		*X = (A - b * (*Y)) / a;
		// cout << ((*X)*a+(*X)*b)-A << endl;
		// cout << ((*Y)*c+(*Y)*d)-B << endl;
		// cout << "dd " << (b*c-a*d) << endl;
		return true;
	}


	double distance(int n, int east, int north) {
		double d = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if ((n % 2 == 0 && abs(j - i) == n / 2)) {
					continue;
				}
				double X, Y;
				bool res = solve(cos(2*M_PI*i/double(n)), sin(2*M_PI*i/double(n)), 
					             cos(2*M_PI*j/double(n)), sin(2*M_PI*j/double(n)), 
					             double(east), double(north), &X, &Y);
				if (res) {
					double r = abs(X) + abs(Y);
					// cout << "[+] " << X << " " << Y << " " << r << endl;
					if (d == -1) {
						d = r;
					}
					d = min(d, r);
				} else {
					// cout << "[-]" << endl;
				}
			}
		}
		return d;
	}
};

int main() {
	Airways x;
	cout << x.distance(3, -219, 0) << " 437.99999999999994" << endl;
	cout << x.distance(3, 171, 0) << " 171.0" << endl;
	cout << x.distance(4, 233, 3111) << " 3344.0000000000005" << endl;
	cout << x.distance(14, -3840, -1768) << " 4243.534462721784" << endl;
	cout << endl;
}