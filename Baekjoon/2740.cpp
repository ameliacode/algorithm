#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;



int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M, K;

	cin >> N >> M;
	int** A = new int*[N];
	for (int i = 0; i < N; i++) {
		A[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	int** B = new int* [M];
	for (int i = 0; i < M; i++) {
		B[i] = new int[K];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}


	int** result = new int* [N];
	for (int i = 0; i < N; i++) {
		result[i] = new int[K];
	}

	//memset(result, 0, N * K * sizeof(int));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}