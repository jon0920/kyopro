#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    ll p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(b.begin(), b.end());

    vector<ll> sum(m + 1);
    for(int i = 1; i <= m; i++) sum[i] = sum[i - 1] + b[i - 1];

    ll ans = 0;
    rep(i,n){
        ll it = lower_bound(b.begin(), b.end(), p - a[i]) - b.begin();
        ans += sum[it] + (it * a[i]) + (p * (m - it));
    }
    cout << ans << endl;
    
    return 0;
}