#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    deque<int> server;
    
    for (int idx = 0;idx < players.size();idx++)
    {
        int curnum = players[idx];
        
        while ((server.size()+1) * m <= curnum)
        {
            //cout << "시간: " << idx << " 인원: " << curnum << endl;
            server.push_back(0);
            answer++;
        }
        
        for(auto& s : server)
        {
            s++;
        }
        
        while(!server.empty() && server.front() >= k)
        {
            server.pop_front();
        }
    }
    
    return answer;
}
