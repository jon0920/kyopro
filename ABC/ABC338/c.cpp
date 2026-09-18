#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
const int INF = 1e9;

int main() {
    
    int n;
    cin >> n;
    vector<ll> q(n), a(n), b(n);
    rep(i,n) cin >> q[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    
    ll ans = 0;
    for(ll x = 0; x <= 1000000; x++){
        ll y = INF;
        rep(i,n){
            if(q[i] < a[i] * x) y = -INF;
            else if(b[i] > 0){
                y = min(y, (q[i] - a[i] * x) / b[i]);
            }
        }
        ans = max(ans, x + y);
    }
    cout << ans << endl;

    return 0;
}