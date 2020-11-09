#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int visited[1001][1001];
    bool down = true, right = false, diag = false;
    int num = 1;
    int x_end = 0, y_end = n;
    int x_start = 1, y_start = 1;

    while (num <= n * (n+1) / 2)
    {
        if (down)
        {
            for (int i = y_start; i <= y_end; i++)
            {
                visited[i][x_start] = num++;
            }
            down = false;
            right = true;
            x_start++;
            y_start++;
        }
        if (right)
        {
            for (int i = x_start; i <= y_end - x_end; i++)
            {
                visited[y_end][i] = num++;
            }
            right = false;
            diag = true;
            y_end--;
        }
        if (diag)
        {
            for (int i = y_end; i >= y_start ; i--)
            {
                visited[i][i - x_end] = num++;
            }
            diag = false;
            down = true;
            x_end++;
            y_start++;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int m = 1; m <= k; m++)
        {
            answer.push_back(visited[k][m]);
        }
    }

    return answer;
}