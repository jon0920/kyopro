#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i,n) cin >> c[i];

    vector<ll> dp(1 << m, INF);
    dp[0] = 0;
    rep(i,n){
        int S = 0;
        rep(j,m){
            int e;
            cin >> e;
            S |= (e << j);
        }
        for(int b = 0; b < (1 << m); b++){
            dp[b | S] = min(dp[b | S], dp[b] + c[i]);
        }
    }

    if(dp[(1 << m) - 1] == INF) cout << -1 << endl;
    else cout << dp[(1 << m) - 1] << endl;

    return 0;
}