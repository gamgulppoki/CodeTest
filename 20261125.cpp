#include <string>
#include <vector>

using namespace std;

vector<vector<int>> vec;
vector<vector<int>> dungeonvec;
int n;
int visited[10];
int result = 0 ;

void dfs(vector<int>& v, int depth, int piro)
{
    if (depth == n)
    {
        vec.push_back(v);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if (visited[i] == -1 && dungeonvec[i][0] <= piro)
        {
            result = max(result, depth+1);
            visited[i] = 1;
            dfs(v, depth+1, piro - dungeonvec[i][1]);
            visited[i] = -1;
        }
    }
}

void simulate(vector<int>& vec)
{
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    n = dungeons.size();
    dungeonvec = dungeons;
    fill (visited, visited + 10, -1);
    
    vector<int> tmpvec;
    dfs(tmpvec, 0, k);
    
    return result;
}
