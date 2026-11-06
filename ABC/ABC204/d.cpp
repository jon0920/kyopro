#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> t(n);
    int sum = 0;
    rep(i,n){
        cin >> t[i];
        sum += t[i];
    }
    vector<bool> dp(sum + 1);
    dp[0] = true;

    rep(i,n){
        vector<bool> ndp = dp;
        for(int j = sum; j >= 0; j--) {
            if(dp[j]) ndp[j + t[i]] = true;
        }
        dp = move(ndp);
    }

    int ans = 1e9;
    rep(i,sum + 1){
        if(dp[i]){
            ans = min(ans, max(i, sum - i));
        }
    }

    cout << ans << endl;
    
    return 0;
}