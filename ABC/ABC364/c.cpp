#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<ll> sa(n, 0), sb(n, 0);
    rep(i,n){
        if(i == 0) sa[i] = a[i], sb[i] = b[i];
        else sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
    }

    ll ix = upper_bound(sa.begin(), sa.end(), x) - sa.begin();
    ll iy = upper_bound(sb.begin(), sb.end(), y) - sb.begin();
    ll ans = min(ix, iy);
    cout << (ans == n ? ans : ans + 1) << endl;
    
    return 0;
}