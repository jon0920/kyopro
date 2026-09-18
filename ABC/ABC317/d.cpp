#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main() {
    
    int n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    ll seat = 0;
    rep(i,n){
        cin >> x[i] >> y[i] >> z[i];
        seat += z[i];
    }

    vector<ll> dp(seat + 1, INF);
    dp[0] = 0;

    rep(i,n){
        ll nx = x[i], ny = y[i], nz = z[i];
        ll change = max(0LL, (nx + ny) / 2 + 1 - nx);
        for(int j = seat; j >= nz; j--){
            chmin(dp[j], dp[j - nz] + change);            
        }
    }

    int h = seat / 2 + 1;
    ll ans = INF;
    for(int i = h; i <= seat; i++){
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;

    
    return 0;
}