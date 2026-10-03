#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> dp_nxt(45, vector<ll>(n));
    vector<vector<ll>> dp_sum(45, vector<ll>(n));

    rep(i,n){
        dp_nxt[0][i] = (i + a[i]) % n;
        dp_sum[0][i] = a[i];
    }

    rep(i,44){
        rep(j,n){
            dp_nxt[i + 1][j] = dp_nxt[i][dp_nxt[i][j]];
            dp_sum[i + 1][j] = dp_sum[i][j] + dp_sum[i][dp_nxt[i][j]];
        }
    }

    ll ans = 0;
    ll cur_mod = 0;
    rep(i,45){
        if((k >> i) & 1){
            ans += dp_sum[i][cur_mod];
            cur_mod = dp_nxt[i][cur_mod];
        }
    }

    cout << ans << endl;
    
    return 0;
}