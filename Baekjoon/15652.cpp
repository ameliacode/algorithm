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

void DFS(int num, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++)
    {
        if (!visited[i])
        {
            //cout << num << endl;
            //visited[i] = true;
            arr[cnt] = i;
            DFS(i , cnt + 1);
            //visited[i] = false;
        }
    }
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;

	DFS(1,0);

	return 0;

}