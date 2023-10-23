#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, float> a, pair<int,float> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,float>> rank;
    
    sort(stages.begin(), stages.end());
    
    for(int i = 1; i <= N;i++)
    {
        float total_players = 0;
        float curr_players = 0;
        for(int j = 0;j < stages.size();j++)
        {
            
            if(i <= stages[j])
            {
                if(i == stages[j]) curr_players++;
                total_players++;
            }
        }
        if (total_players == 0) rank.push_back(make_pair(i, 0));            //0이 분모인 수는 존재하지 않으므로 따로 처리해야 함 
        else rank.push_back(make_pair(i, curr_players/total_players));
    }
    sort(rank.begin(), rank.end(), compare);
    
    for(int i = 0; i < rank.size();i++)
    {
        answer.push_back(rank[i].first);
    }
    
    return answer;
}