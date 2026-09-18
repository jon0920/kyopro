#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> dp(n, INF);
    dp[0] = 0;
    
    rep(i,n - 1){
        for(int j = 1; j <= 2; j++){
            if(i + j >= n) continue;
            dp[i + j] = min(dp[i + j], dp[i] + max(a[i + j] - a[i], 0LL));
        }
    }

    cout << dp[n - 1] << endl;
    
    return 0;
}