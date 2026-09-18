#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, s, m, l;
    cin >> n >> s >> m >> l;

    const int INF = 1e9;
    vector<int> dp(n + 13, INF);
    dp[0] = 0;

    for(int i = 0; i <= n + 12; i++){
        if(i + 6 <= n + 12) dp[i + 6] = min(dp[i + 6], dp[i] + s);
        if(i + 8 <= n + 12) dp[i + 8] = min(dp[i + 8], dp[i] + m);
        if(i + 12 <= n + 12) dp[i + 12] = min(dp[i + 12], dp[i] + l);
    }
    
    int ans = INF;
    for(int i = n; i <= n + 12; i++){
        ans = min(dp[i], ans);
    }
    cout << ans << endl;
    
    return 0;
}