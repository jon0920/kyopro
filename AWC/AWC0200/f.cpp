#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n - 1), c(n - 1);
    rep(i,n - 1) cin >> b[i] >> c[i];

    vector<ll> dp(m + 1, -1);
    dp[m] = 0;

    rep(i,n - 1){
        vector<ll> ndp(m + 1, -1);
        for(int j = m; j >= 0; j--){
            if(dp[j] != -1){
                if(j - a[i] < 0) continue;
                ndp[j - a[i]] = max(ndp[j - a[i]], dp[j]);
            }
        }
        vector<ll> nndp(m + 1, -1);
        rep(j,m + 1){
            if(ndp[j] != -1){
                nndp[min(m, j + b[i])] = max(nndp[min(m, j + b[i])], ndp[j]);
                nndp[j] = max(nndp[j], ndp[j] + c[i]);
            }
        }
        dp = move(nndp);
    }
    vector<ll> ndp(m + 1, -1);
    for(int j = m; j >= 0; j--){
        if(dp[j] != -1){
            if(j - a[n - 1] < 0) continue;
            ndp[j - a[n - 1]] = max(ndp[j - a[n - 1]], dp[j]);
        }
    }
    dp = move(ndp);

    cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}