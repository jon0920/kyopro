#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p >> d[i];
        G[p].push_back(i);
    }

    int ans = 0;

    auto dfs = [&](auto dfs, int x) -> bool {
        int infected_cnt = 0;
        for(int nx : G[x]){
            if(dfs(dfs, nx)) infected_cnt++;
        }
        if(x == 0) return false;

        int total = G[x].size();
        if(d[x] > 0 || (total - infected_cnt) < infected_cnt){
            ans++;
            return true;
        }
        return false;
    };

    dfs(dfs, 0);

    cout << ans << endl;
    
    return 0;
}