#include <bits/stdc++.h>
#define ll long long
#define pii pair <ll, ll>
#define st first
#define nd second
#define rep(i, n, m) for (int i = n; i <= m; i ++)
#define rrep(i, n, m) for (int i = n; i >= m; i --)
#define file "input"

using namespace std;

const long long N = 2e5 + 5;
const long long inf = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #if !defined(ONLINE_JUDGE)
    #define ONLINE_JUDGE
        freopen(file".txt", "r", stdin);
    #endif // ONLINE_JUDGE

    vector <ll> a, b;
    ll x, y;
    while (cin >> x >> y) {
        a.push_back(x);
        b.push_back(y);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    int j = 0;
    for (int i = 0; i < a.size();) {
        int t = i;
        while (t < a.size() && a[t] == a[i]) t ++;
        while (j < b.size() && b[j] < a[i]) j ++;
        while (j < b.size() && b[j] == a[i]) ans += a[i] * (t - i), j ++;
        i = t;
    }

    cout << ans;


    return 0;
}