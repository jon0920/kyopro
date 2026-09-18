#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<ll> b(n), w(m);
    rep(i,n) cin >> b[i];
    rep(i,m) cin >> w[i];

    sort(b.rbegin(),b.rend());
    sort(w.rbegin(),w.rend());

    vector<ll> s(n+1,0), t(m+1,0), tmax(m+1,0);
    rep(i,n){
        s[i+1] = s[i] + b[i];
    }
    rep(i,m){
        t[i+1] = t[i] + w[i];
        tmax[i+1] = max(tmax[i], t[i+1]);
    }

    ll ans = 0;
    rep(i,n+1){
        ans = max(ans, s[i] + tmax[min(i,m)]);
    }
    
    cout << ans << endl;
    return 0;
}