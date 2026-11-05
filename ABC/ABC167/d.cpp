#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> dp(60, vector<int>(n));
    rep(i,n){
        dp[0][i] = a[i];
    }

    for(int i = 0; i < 59; i++){
        rep(j,n){
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    int cur = 0;
    rep(i,60){
        if((k >> i) & 1) cur = dp[i][cur]; 
    }

    cout << cur + 1 << endl;
    
    return 0;
}