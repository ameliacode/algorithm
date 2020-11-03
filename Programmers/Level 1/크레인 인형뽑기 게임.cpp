#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int i, j;
    stack<int> s;
    
    for(i = 0;i<moves.size();i++)
    {
        int temp;
        for(j = 0 ;j<board.size();j++)
        {
            if(board[j][moves[i] - 1] != 0)
            {
                temp = board[j][moves[i] - 1];
                if (s.empty())
                {
                    s.push(temp);
                }
                else{
                    if(s.top() == temp)
                    {
                        //cout << s.top() << " "<<temp<<endl;
                        answer+=2;            
                        s.pop();
                    }
                    else s.push(temp);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }        
    }
    return answer;
}