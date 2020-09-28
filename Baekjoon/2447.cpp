#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

char map[3000][3000];

void init()
{
	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j < 3000; j++) {
			map[i][j] = ' ';
		}
	}
}

void aster_print(int n, int x, int y) 
{
	if (n == 1){
		map[x][y] = '*';
		return;
	}
	else {
		int div = n / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				aster_print(div, x + (div * i), y + (div * j));
			}
		}
	}
	return;
}

int main()
{
	int N;
	cin >> N;

	init();
	aster_print(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
