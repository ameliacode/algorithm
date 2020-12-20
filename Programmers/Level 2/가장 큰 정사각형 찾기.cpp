#include <iostream>
#include<vector>
using namespace std;

//구글 찬스.. DP를 이용하여 각 변을 조사하여 정사각형의 최대 길이를 구한다.
int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int height = board.size();
    int width = board[0].size();
    
    for(int i = 1;i < height; i++){
        for(int j = 1; j < width; j++){
            if(board[i][j] == 1)   //길이가 1인 경우에만 정사각형으로 인정하므로
            {
                board[i][j] = min(board[i - 1][j - 1], board[i][j - 1]);
                board[i][j] = min(board[i][j], board[i - 1][j]) + 1;
                answer = max(board[i][j], answer);
            }           
        }
    }  

    return answer*answer;
}