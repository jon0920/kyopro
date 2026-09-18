#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> e;
        rep(i,m){
            int u, v;
            cin >> u >> v;
            u--, v--;
            e.push_back({u, v});
            e.push_back({v, u});
        }
        int w;
        cin >> w;
        vector<string> s(n);
        rep(i,n) cin >> s[i];
        rep(i,n) e.push_back({i, i});
        
        int sz = n * w;
        vector<vector<int>> G(sz);
        for(auto [x, y] : e){
            rep(i,w){
                int j = (i + 1) % w;
                if(s[x][i] == 'o' && s[y][j] == 'o') G[n * i + x].push_back(n * j + y);
            }
        }

        vector<bool> visited(sz), finished(sz);
        auto dfs = [&](auto dfs, int v){
            if(visited[v]) return false;
            visited[v] = true;
            for(auto nv : G[v]){
                if(finished[nv]) continue;
                if(visited[nv] || dfs(dfs, nv)) return true;
            }
            finished[v] = true;
            return false;
        };

        bool ans = false;
        rep(i,n){
            if(dfs(dfs, i)) ans = true;
        }

        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}