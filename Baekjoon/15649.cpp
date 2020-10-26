#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

int N, M;
bool visited[9] = { 0, };
int arr[9] = { 0, };

void DFS(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;

	DFS(0);

	return 0;

}