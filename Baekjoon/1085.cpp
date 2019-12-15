#include<iostream>
#include<string>

using namespace std;

int Rectangle(int x, int y, int w, int h) {
	int a, b, c, d;
	int min1, min2;
	a = w - x;
	b = x;
	c = h - y;
	d = y;
	min1 = a > b ? b : a;
	min2 = c > d ? d : c;
	return min1 > min2 ? min2 : min1;
}

int main() {

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << Rectangle(x, y, w, h) << endl;
}
