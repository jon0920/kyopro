#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){
    
    int s;
    cin >> s;
    vector<mint> dp(s + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= s; i++){
        for(int j = 0; j <= i - 3; j++) dp[i] += dp[j];
    }
    cout << dp[s].val() << endl;
    
    return 0;
}