#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
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

    vector<int> down(n), up(n);

    auto dfs1 = [&](auto dfs1, int v, int p) -> int {
        vector<int> childvals;
        for(int nv : G[v]){
            if(nv == p) continue;
            childvals.push_back(dfs1(dfs1, nv, v));
        }
        sort(childvals.rbegin(), childvals.rend());
        int res = 1;
        if(childvals.size() >= 3) res = 1 + childvals[0] + childvals[1] + childvals[2];
        return down[v] = res;
    };

    dfs1(dfs1, 0, -1);

    int ans = -1;
    auto dfs2 = [&](auto dfs2, int v, int p) -> void {
        vector<pair<int,int>> arms;
        for(int nv : G[v]){
            if(nv != p) arms.push_back({down[nv], nv});
        }
        if(p != -1) arms.push_back({up[v], -1});

        sort(arms.rbegin(), arms.rend());
        while(arms.size() > 4) arms.pop_back();
        if(arms.size() == 4){
            int sum = 0;
            rep(i,4) sum += arms[i].first;
            ans = max(ans, sum + 1);
        }

        for(int nv : G[v]){
            if(nv == p) continue;
            vector<pair<int,int>> rest;
            for(auto arm : arms){
                if(arm.second != nv) rest.push_back(arm);
            }

            up[nv] = rest.size() >= 3 ? 1 + rest[0].first + rest[1].first + rest[2].first : 1;
            dfs2(dfs2, nv, v);
        }
    };
    
    dfs2(dfs2, 0, -1);

    cout << ans << endl;
    
    return 0;
}