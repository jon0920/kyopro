#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k, p;
    cin >> n >> k >> p;
    vector<ll> c(n);
    vector<vector<int>> a(n, vector<int>(k));
    rep(i,n){
        cin >> c[i];
        rep(j,k) cin >> a[i][j];
    }

    int mx = 1;
    rep(j,k) mx *= (p + 1);

    vector<ll> dp(mx, INF);
    dp[0] = 0;

    rep(i,n){
        for(int now = mx - 1; now >= 0; now--){
            if(dp[now] == INF) continue;
            vector<int> cur(k);
            int temp = now;
            rep(j,k){
                cur[j] = temp % (p + 1);
                temp /= (p + 1);
            }

            int nxt = 0;
            int b = 1;
            rep(j,k){
                int nxt_val = min(p, cur[j] + a[i][j]);
                nxt += nxt_val * b;
                b *= (p + 1);
            }
            dp[nxt] = min(dp[nxt], dp[now] + c[i]);
        }
    }

    ll ans = dp[mx - 1];
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}