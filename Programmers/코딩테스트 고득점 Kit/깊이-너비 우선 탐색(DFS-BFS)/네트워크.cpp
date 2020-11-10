#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n)
{
    if(!computers[n][n]) return false;          //diag value가 1이 아닐 경우 false        
    computers[n][n]= 0;                         //방문했으므로 0으로 만들어준다,
    
    for(int i = 0;i<computers.size();i++)       
    {
        if(computers[n][i]) dfs(computers, i);     //해당 노드들을 dfs로 방문
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n;i++) 
    {
        if(computers[i][i] && dfs(computers,i)) answer++;
    }
    
    return answer;
}