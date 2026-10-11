#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<vector<int>> G(n);
        rep(i,n - 1){
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int ans = 1;
        auto dfs = [&](auto dfs, int v, int p) -> int {
            vector<int> dp;
            for(int nv : G[v]){
                if(nv != p) dp.push_back(dfs(dfs, nv, v));
            }
            int res = 0;
            sort(dp.rbegin(), dp.rend());
            if(G[v].size() >= 4){
                res = dp[0] + 1;
                ans = max(ans, dp[0] + dp[1] + 1);
            }
            if(G[v].size() == 3){
                res = 1;
                ans = max(ans, dp[0] + 1);
            } 
            return res;
        };

        dfs(dfs, 0, -1);

        cout << ans << '\n';
    }
    
    return 0;
}