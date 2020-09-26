#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define PI 3.14159265358979323846


int main() {

	int T;
	int x1, y1, x2, y2, r1, r2;
	int flag = 0;

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double total_rad = r1 + r2;
		double euclid_dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		
		if (r1 == r2 && x1 == x2 && y1 == y2) flag = -1;
		else {
			int max_rad = r1 > r2 ? r1 : r2;
			int min_rad = r1 < r2 ? r1 : r2;

			if (euclid_dist > max_rad) {	//외접part
				if (total_rad < euclid_dist) flag = 0;
				else if (total_rad == euclid_dist) flag = 1;
				else if (total_rad > euclid_dist) flag = 2;
			}
			else {			//내접part
				if (max_rad == euclid_dist + min_rad) flag = 1;
				else if (max_rad > euclid_dist + min_rad) flag = 0;
				else if (max_rad < euclid_dist + min_rad) flag = 2;
			}
		}
		
		cout << flag <<endl;
	}
		
	return 0;
}