#include<iostream>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string board[50];

int WB_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			if (board[x + i][y + j] != WB[i][j]) 
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int BW_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			if (board[x + i][y + j] != BW[i][j]) 
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {

	int M, N, min_val=99999;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int i = 0; i + 8 <= N; i++) {
		for (int j = 0; j + 8 <= M; j++) {
			int temp;
			temp = min(WB_cnt(i, j), BW_cnt(i, j));
			if (temp < min_val) {
				min_val = temp;
			}
		}

	}
	cout << min_val << endl;
	
	return 0;
}