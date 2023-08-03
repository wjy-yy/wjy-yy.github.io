#include <bits/stdc++.h>

using namespace std;

const int N = 310;

class Nobe {
	public:
		int l, r;
		Nobe(int x, int y);
		inline bool fault();
};

inline int read(void);
inline void dp(void);
inline void prep(void);
inline void bfs(int, int);

int n, a[N], f[N][N], pos[N][N];
queue <Nobe> q;

int main() {
	prep();
	dp();
	printf("%d\n", f[1][n]);
	bfs(1, n);
	
	return 0;
}

inline int read(void) {
	int res = 0;
	char c = getchar();
	
	for (; !isdigit(c); c = getchar());
	
	for (; isdigit(c); res = res * 10 + c - '0', c = getchar());
	
	return res;
}

inline void prep(void) {
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
}

inline void dp(void) {
	for (int L = 2; L <= n; ++L) {
		for (int i = 1; i <= n - L + 1; ++i) {
			int j = i + L - 1;
			
			for (int k = i; k < j; ++k) {
				if (f[i][k] + f[k + 1][j] + (a[i] + a[j]) * a[k] > f[i][j]) {
					pos[i][j] = k;
					f[i][j] = f[i][k] + f[k + 1][j] + (a[i] + a[j]) * a[k];
				}
			}
		}
	}
}

inline void bfs(int x, int y) {
	Nobe tmp(x, y);
	
	while (!q.empty()) {
		tmp = q.front();
		if (tmp.fault()) {
			q.pop();
			continue;
		}
		printf("%d ", pos[tmp.l][tmp.r]);
		int k = pos[tmp.l][tmp.r], rr = tmp.r;
		tmp.r = k;
		q.push(tmp);
		tmp.l = k + 1;
		tmp.r = rr;
		q.push(tmp);
		q.pop();
	}
	
}

Nobe::Nobe(int x, int y) { //构造函数
	l = x;
	r = y;
	q.push(*this);
}

inline bool Nobe::fault() {
	return l == r;
}