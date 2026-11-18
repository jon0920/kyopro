#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int mx = 100010;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    vector<bool> dp(mx);
    dp[0] = true;

    rep(i,n){
        vector<bool> ndp(mx);
        rep(j,mx){
            if(!dp[j]) continue;
            ndp[j] = true;
            if(j + a[i] < mx) ndp[j + a[i]] = true;
        }
        dp = move(ndp);
    }

    int ans = 1e9;
    rep(i,mx){
        if(dp[i]){
            ans = min(ans, abs(i - (sum - i)));
        }
    }

    cout << ans << endl;
    
    return 0;
}