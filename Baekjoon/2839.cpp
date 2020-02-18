#include<iostream>
#include<string>

using namespace std;

int SugarDelivery(int N) {
	int total = -1;
	int five = N / 5;
	int three = 0;
	int leftover;
	while (1) {
		leftover = N - 5 * five;
		//cout << leftover << endl;
		if (leftover % 3 != 0) {
			five--;
			//cout << "!!" << endl;
		}
		else {
			three = leftover / 3;
			total = five + three;
			//cout << leftover << endl;
			//cout << five<< " "<<three << endl;
			break;
		}
		if (five < 0) break;
	}
	
	return total;
}

int main() {
	int N;

	cin >> N;
	cout << SugarDelivery(N) << endl;

}