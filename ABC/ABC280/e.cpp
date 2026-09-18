#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n, p;
    cin >> n >> p;
    vector<mint> dp(n + 1, 0);
    mint a = (mint)p / 100;
    mint b = 1 - a;

    for(int i = 1; i <= n; i++){
        dp[i] = (dp[max(0, i - 2)] * a + dp[i - 1] * b) + 1;
    }

    cout << dp[n].val() << endl;

    return 0;
}