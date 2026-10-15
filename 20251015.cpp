#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int pos = 0;
    
    priority_queue<int, vector<int>> pq; 
    
    while(n >= 0 && pos < enemy.size())
    {
        pq.push(enemy[pos]);
        n -= enemy[pos++];
        if (n < 0 && k > 0)
        {
            int top = pq.top();
            pq.pop();
            n += top;
            k--;
        }
        else if (n < 0 && k <= 0)
        {
            pos--;
        }
    }
    
    answer = pos;
    return answer;
}
