#include <string>
#include <vector>

using namespace std;

int answer = 100;   //단어는 50개 이하이므로 51개로 설정해도 무관
void dfs(string begin, string target, vector<string> words, vector<bool> &word_check,int dist)
{
    for(int i = 0;i < words.size();i++)     //words에 있는 단어들 중에서
    {   
        int count = 0;
        for(int j = 0;j< words[i].length();j++)     //한 번에 한 개의 알파벳만 바꿀 수 있으므로
        {
            if(!word_check[i] && words[i][j] != begin[j]) count++;
        }
        if(count == 1)  //조건에 맞는 단어를 찾는다면
        {            
            if(target == words[i])  //target이랑 같으면 더 이상 찾을 이유가 없으므로 stop
            {
                if(answer > dist + 1) 
                {
                    answer = dist + 1;
                    return;
                }
            }
            else{
                if(!word_check[i])  //방문한 적이 없는 단어라면, true로 갱신
                {
                    word_check[i] =  true;
                    dfs(words[i], target, words, word_check, dist + 1);
                }
            }       
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    vector<bool> word_check(words.size(), false);
    dfs(begin, target, words, word_check, 0);
    if(answer == 100)
    {
        return 0;
    }
    
    return answer;
}