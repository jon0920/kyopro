#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> G(n);
    rep(i,m){
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }

    vector<int> res(n, 0);
    vector<bool> seen(n);
    vector<vector<int>> group;
    int cur = 0;

    bool ok = true;
    rep(i,n){
        if(!seen[i]){
            queue<pair<int,int>> que;
            que.push({i, 0});
            group.push_back({});
            group[cur].push_back(i);
            seen[i] = true;
            while(!que.empty()){
                auto [v, s] = que.front(); que.pop();
                for(auto [nv, t] : G[v]){
                    if(seen[nv]){
                        if((s ^ res[nv]) != t) ok = false;
                    } else {
                        group[cur].push_back(nv);
                        seen[nv] = true;
                        res[nv] = s ^ t;
                        que.push({nv, res[nv]});
                    }
                }
            }
            cur++;
        }
    }

    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans(n);
    for(auto &vec : group){
        vector<ll> cnt(31);
        ll sz = vec.size();
        int mask = 0;
        for(int x : vec){
            rep(i,31){
                if((res[x] >> i) & 1) cnt[i]++;
            }
        }
        rep(i,31){
            if(cnt[i] > (sz - cnt[i])) mask ^= (1 << i);
        }
        for(int x : vec){
            ans[x] = res[x] ^ mask;
        }
    }

    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}