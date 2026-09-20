// 20260920 전력망을 둘로 나누기

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int map[104][104];
int visited[104];
int N;

// 트리라서 무조건 하나는 끊기게 됨

int dfs(int idx, vector<int>& w)
{
    int cnt = 1;
    visited[idx] = 1;
    
    int f = w[0]; int s = w[1];
    
    for(int i=1;i<=N;i++)
    {
        if (map[idx][i] == 1 && visited[i] == -1)
        {
            if ((f == idx && s == i) || (f == i && s == idx))
            {
                continue;
            }
            cnt += dfs(i, w);
        }
    }
    
    return cnt;
}

int go(vector<int>& w)
{
    vector<int> cntvec;
    
    memset(visited, -1, sizeof(visited));
    
    for(int i = 1; i <= N; i++)
    {
        if (visited[i] == -1)
        {
            cntvec.push_back(dfs(i, w));
        }
    }
    
    return abs(cntvec[0] - cntvec[1]);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    N = n;
    
    memset(map, -1, sizeof(map));
    
    // 인접맵 만들어주기
    for(auto& w : wires)
    {
        int first = w[0]; int second = w[1];
        
        map[first][second] = 1;
        map[second][first] = 1;
    }
    
    // 각 간선 끊어서 측정해보기
    for(auto& w : wires)
    {
        int ret = go(w);
        answer = min(answer, ret);
    }
    
    return answer;
}
