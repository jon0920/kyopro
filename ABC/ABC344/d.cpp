#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string t;
    cin >> t;
    int sz = t.size();
    int n;
    cin >> n;
    vector<vector<string>> s(n);
    rep(i,n){
        int a;
        cin >> a;
        s[i].resize(a);
        rep(j,a) cin >> s[i][j];
    }

    vector<int> dp(sz + 1, 1e9);
    dp[0] = 0;

    rep(i,n){
        vector<int> ep = dp;
        rep(j,sz){
            if(dp[j] == 1e9) continue;
            for(string str : s[i]){
                int m = str.size();
                if(j + m > sz) continue;
                string tmp = t.substr(j,m);
                if(tmp == str){
                    ep[j + m] = min(ep[j + m], dp[j] + 1);
                }
            }
        }
        dp = ep;
    }

    if(dp[sz] == 1e9) cout << -1 << endl;
    else cout << dp[sz] << endl;
    
    return 0;
}