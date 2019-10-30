#include<iostream>
#include<string>

using namespace std;

int* binary(int num, int size) {
	int *temp = new int[size];
	for (int i = 0; i < size; i++) {
		*(temp + size - i - 1) = num % 2;
		num = num / 2;
	}
	return temp;
}

void map(int *arr1, int *arr2, int size) {
	int *temp1 = new int[size];
	int *temp2 = new int[size];
	for (int i = 0; i < size; i++) {
		temp1 = binary(arr1[i], size);
		temp2 = binary(arr2[i], size);
		for (int j = 0; j < size; j++) {
			if (temp1[j] == 0 && temp2[j] == 0) cout << " ";
			else cout << "#";
		}
		cout << endl;
	}
}

int main() {
	int n;
	int *arr1;
	int *arr2;
	cin >> n;
	arr1 = new int[n];
	arr2 = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	map(arr1, arr2, n);
}//copyright 2019 github @ ameliacode