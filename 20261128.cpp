#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int board[54][54];
int visited[54][54];

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
	memset(board, 500, sizeof(board));

	vector<pair<int, int>> shark;

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;

			board[i][j] = 500;
			if (tmp == 1)
			{
				shark.push_back({ i,j });
				board[i][j] = -2;
			}
		}
	}

	for (auto& s : shark)
	{
		memset(visited, -1, sizeof(visited));
		queue<pair<int, int>> q;

		q.push(s);
		visited[s.first][s.second] = 0;

		while (!q.empty())
		{
			int cy = q.front().first; int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++)
			{
				int ny = cy + dy[i]; int nx = cx + dx[i];
				if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] != -1) continue;

				visited[ny][nx] = visited[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}


		for (int y = 0; y < m; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (board[y][x] == -2) continue;

				board[y][x] = min(board[y][x], visited[y][x]);
			}
		}


	}

	int answer = 0;

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			answer = max(answer, board[y][x]);

		}
	}

	cout << answer;
	return 0;
}

