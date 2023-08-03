#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
pair<int, int> q[2005000];
#define mp make_pair
int ql;

int n, m, W;
int a[1055][1055];
bool vis[1055][1055];
int ans;

void bfs(int x, int y) {
	q[ql = 1] = mp(x, y);
	pair<int, int> p;
	for (int j = 1; j <= ql; ++j) {
		p = q[j];
		for (int t = 0; t < 4; ++t) {
			x = p.first + dx[t], y = p.second + dy[t];
			if (x && x <= n && y && y <= m && abs(a[x][y] - a[p.first][p.second]) <= W && !vis[x][y]) {
				q[++ql] = mp(x, y);
				vis[x][y] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &W);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	memset(vis, 0, sizeof(vis));
	ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!vis[i][j]) {
				++ans;
				vis[i][j] = 1;
				bfs(i, j);
			}
	printf("%d\n", ans);
}