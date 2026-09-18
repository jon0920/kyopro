#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string S, T;
    cin >> S >> T;
    int n = S.size(), m = T.size();

    vector<ll> dp(m + 1, 0);
    ll ans = 0;
    
    ll l = 0;
    rep(r,n){
        vector<ll> ep(m + 1, 0);
        dp[0]++;
        rep(j,m){
            if(dp[j] == 0) continue;
            if(S[r] == T[j]){
                ep[j + 1] += dp[j];
            } else {
                ep[j] += dp[j]; 
            }
        }

        l += ep[m];
        ans += r + 1 - l;

        ep[m] = 0;
        dp = ep;
    }

    cout << ans << endl;

    return 0;
}