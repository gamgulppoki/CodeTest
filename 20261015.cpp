#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

vector<vector<int>> vec;
int adj[104][104];
int infected[104];
int N;

void dfs(vector<int>& v, int depth)
{
    if (depth >= N) 
    {
        vec.push_back(v);
        return;
    }
    
    for(int i=1;i<=3;i++)
    {
        v.push_back(i);
        
        dfs(v, depth+1);
        
        v.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    N = k;
    memset(adj, -1, sizeof(adj));
    memset(infected, -1, sizeof(infected));
    
    vector<int> tmp;
    dfs(tmp,0);
    
    // adj 작업
    for(auto& e : edges)
    {
        adj[e[0]][e[1]] = e[2];
        adj[e[1]][e[0]] = e[2];
    }
    
    for(auto& v : vec)
    {
        memset(infected, -1, sizeof(infected));
        infected[infection] = 1;
        queue<int> q;
        
        q.push(infection);
        
        int visited[104];
        memset(visited, -1, sizeof(visited));
        visited[infection] = 1;
        
        for(auto& idx : v)
        {
            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                
                for(int i=0;i<=n;i++)
                {
                    if (adj[cur][i] == idx && infected[i] == -1 && visited[i] == -1)
                    {
                        q.push(i);
                        visited[i] = 1;
                        infected[i] = 1;
                    }
                }
            }
            
            for(int i=0;i<=n;i++)
            {
                if (infected[i] == 1) q.push(i);
            }
        }
        
        int cnt = 0;
        for(int i=0;i<=n;i++)
        {
            if (infected[i] == 1) 
            {
                cnt++;
                //cout << i << " " ;
            }
        }
        //cout << endl;
        answer = max(answer, cnt);
    }
    
    return answer;
}
