#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_depth = 0;

//구글 찬스.. 티켓을 모두 소진했냐라는 부분 해결하기에는 너무 어려웠다,
void dfs(string depart, vector<vector<string>> tickets, vector<bool>&used, vector<string> &answer, vector<string> &temp, int depth)
{
    temp.push_back(depart); //임시 queue에 출발지를 push
    if(max_depth < depth){  //최대 depth보다 큰 depth가 나타나면 갱신
        max_depth = depth;  //이미 최대 depth(모두 소진한 가정)에서 
        answer = temp;      //정답을 갱신
    }
    
    for(int i = 0;i<tickets.size();i++)
    {
        if(depart == tickets[i][0] && !used[i]){ //한번도 사용한 적이 없고 티켓 출발지와 동일한 티켓이라면
            used[i] = true;    
            dfs(tickets[i][1], tickets, used, answer,temp, depth + 1); 
            used[i] = false; //뒤로 후진하여 다른 경우의 수 확인 
        }
    }
    for(int i =0;i<temp.size();i++){  //주석 내용 확인 
        cout << temp[i]<<" ";
    }
    cout << endl;
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    vector<bool> used(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, used, answer, temp, 0);
    
    return answer;
}