#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define PI 3.14159265358979323846


int main() {

	int r;

	cin >> r;

	double euclid_area = PI * r * r;
	double taxi_area = 2 * r * r;

	cout << fixed;
	cout.precision(6);
	cout << euclid_area << endl << taxi_area << endl;
		
	return 0;
}