#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define show(a) for(auto &i : a) cout << i << ' ';
#define in(a) for(auto &i : a) cin >> i;
int t = 1;

void solve()
{
    int n;
    cin >> n;
    ll x; cin >> x;
    ll a[n]; in(a);
    unordered_map<ll, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        mp[a[i] * a[i]]++;
        if (x - a[i] < 0) continue;
        if (mp.find(x - a[i]) != mp.end()) cnt += mp[x - a[i]];
    }
    cout << cnt << endl;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
