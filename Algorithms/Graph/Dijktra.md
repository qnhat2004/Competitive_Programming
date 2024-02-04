# Thuật toán Dijktra
## Ý tưởng: 
- Thuật toán Dijktra tối ưu hóa bằng cách, xét các cạnh **(u, v)**, so sánh đường đi từ **S->v** và **S->u->v**, từ đó tìm được đỉnh trung gian **u** sao cho độ dài cạnh tìm được **chắc chắn** đạt giá trị nhỏ nhất
- Cụ thể: 
    + Gọi D(u) là độ dài đường đi ngắn nhất từ nguồn tới u, ban đầu khởi tạo D(nguồn) = 0, D(u) = INF.
    + Khi xét đỉnh u hiện tại, xét các cạnh **(u, v)** sao cho: 
        + **v** chưa được thăm
        + **D(v) = min(D(v), D(u) + (u, v))**
- Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    int v;
    ll w;
};

void Dijktra(int n, int s, const vector<vector<Edge>> &E, vector<ll> &D, vector<int> &trace)
{
    D.resize(n, LLONG_MAX);
    trace.resize(n, -1);

    vector<bool> P(n, false);
    D[s] = 0;

    for (int i = 0; i < n; ++i)
    {
        int ubest; // Tìm đỉnh u chưa dùng, có khoảng cách nhỏ nhất
        ll Min = LLONG_MAX;
        for (int u = 0; u < n; ++u)
        {
            if (D[u] < Min && P[u] == false)
            {
                ubest = u;
                Min = D[u];
            }
        }

        // Cải tiến các đường đi qua u
        int u = ubest;
        P[u] = true;
        for (auto x : E[u])
        {
            int v = x.v;
            ll w = x.w;
            if (D[v] > D[u] + w)
            {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}

int main()
{
    int n, m, s;
    // cin >> n >> m >> s;
    n = 7, m = 8, s = 0;
    vector<vector<Edge>> E(n);

    E = {
            {{2, 7}, {1, 1}, {3, 4}},
            {{4, 3}},
            {{5, 8}, {4, 3}},
            {},
            {{5, 6}},
            {{3, 3}},
            {}
    };

    // for (int i = 0; i < m; ++i)
    // {
    //     int u, v;
    //     ll w;
    //     cin >> u >> v >> w;
    //     E[u].push_back({v, w}); // Tức là cạnh (u, v) có trọng số w
    //     // E[v].push_back({u, w});
    // }

    vector<ll> D;
    vector<int> trace;
    Dijktra(n, s, E, D, trace);
    for (auto x : D)
    {
        if (x != LLONG_MAX)
            cout << x << '\n';
        else
            cout << "-1\n";
    }
        
    return 0;
}
```
