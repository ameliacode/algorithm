#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack <int> st;

    int size = prices.size();
    for (int i = 0; i < size; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }

    return answer;
}

int main() {
    vector<int> prices{ 1,2,3,2,3 };
    vector<int> answer = solution(prices);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}