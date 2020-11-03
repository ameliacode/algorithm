#include <string>
#include <vector>
#include <iostream>

using namespace std;

//이전 접근: brown - (row+col) * 2 가 4로 나누어떨어질 때 그만큼 row , col 2만큼 더해줌 -> 복잡..
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int row, col;
    int length = brown+yellow;      //yellow brown 따로 생각하지 말고 합산해서 먼저 접근
    for(row = 3; row < length;++row){
        if(length % row == 0)
        {
            col = length / row;     //전체 row, col 구하기
            if ((((row + col) * 2) - 4 == brown) && yellow + brown == length) 
            {
                answer.push_back(col);
                answer.push_back(row);
                break;
            }
        }
    }    
    return answer;
}