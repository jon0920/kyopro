#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    int n;
    string s = ".";
    string ss;
    cin >> n >> ss;
    s += ss; 
    vector<mint> dp(n + 1, 0);
    dp[0] = 1;
    rep(i,n + 1){
        if(s[i] == '#') continue;
        for(int j = 1; j <= 3; j++){
            if(i + j > n) break;
            if(s[i + j] == '.') dp[i + j] += dp[i];
        }
    }

    cout << dp[n].val() << endl;
    
    return 0;
}