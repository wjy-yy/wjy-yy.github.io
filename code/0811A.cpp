#include <bits/stdc++.h>
using namespace std;//

typedef long long ll;

const int N = 5010;
const ll inf = 9 * 1e18;

ll mp[N][N], f[N];
int n, t, mi, T;
ll ans;

struct node {
    ll x, y;
} a[N];

//len函数的作用是直接计算x点与y点之间的距离
ll len(int x, int y) {
    return (a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i].x, &a[i].y);

    for (int i = 1; i <= n; i++) {
        mp[i][i] = 0;
        for (int j = i + 1; j <= n; j++)
            mp[i][j] = mp[j][i] = len(i, j);
    }

    for (int i = 1; i <= n; i++)
        f[i] = mp[1][i];
    f[1] = inf;

    ans = 0;
    for (int k = 1; k < n; k++) {
        mi = 1;
        for (int i = 2; i <= n; i++)
            if (f[mi] > f[i])
                mi = i;
        //找到上一个点到其他点的最短路，记为mi点


        t = 1;
        for (int i = 1; i <= n; i++)
            if (f[i] == inf && (mp[t][mi] > mp[i][mi]))
                t = i;
        //找到其他点到mi的最短路


        ans = max(ans, mp[t][mi]);
        f[mi] = inf;
        //更新ans并且确定mi点的最短路，更新成inf，以后不再查找。


        for (int i = 1; i <= n; i++)
            if (f[i] != inf)
                f[i] = min(f[i], mp[mi][i]);
        //更新mi到其他点的最短路，若其他点的最短路确认（即f[i] == inf）则忽略。
    }

    printf("%lld\n", ans);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}