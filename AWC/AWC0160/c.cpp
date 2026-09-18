#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> r(n);
    rep(i,m){
        ll P, R;
        cin >> P >> R;
        P--;
        r[P] = R;
    }

    vector<ll> dp(n, -1);
    if(k - h[0] < 0){
        cout << -1 << endl;
        return 0;
    }
    dp[0] = k - h[0] + r[0];

    rep(i,n - 1){
        if(dp[i] <= -1) continue;
        for(int j = 1; j <= 2; j++){
            if(i + j >= n) continue;
            if(dp[i] - h[i + j] >= 0){
                dp[i + j] = max(dp[i + j], dp[i] - h[i + j] + r[i + j]);
            }
        }   
    }

    cout << dp[n - 1] << endl;
    
    return 0;
}