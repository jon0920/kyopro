#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i,n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> c(n);
    rep(i,n) cin >> c[i];

    auto BFS = [&](int init){
        vector<int> dist(n, -1);
        queue<int> que;
        que.push(init);
        dist[init] = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int nv : G[v]){
                if(dist[nv] == -1){
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
            }
        }
        return dist;
    };
    
    vector<int> dist1 = BFS(0);
    int s = 0;
    rep(i,n) if(dist1[i] > dist1[s]) s = i;

    vector<int> dist_s = BFS(s);
    int t = 0;
    rep(i,n) if(dist_s[i] > dist_s[t]) t = i;

    vector<int> dist_t = BFS(t);
    int D = *max_element(dist_t.begin(), dist_t.end());

    auto count = [&](int v, int d){
        vector<ll> cnt(n + 1);
        ll res = 0;

        /*

        */

        return res;
    };

    if(D % 2 == 0){
        int o;
        rep(i,n){
            if(dist_s[i] + dist_t[i] == D && dist_t[i] == D / 2){
                o = i;
                break;
            }
        }

        vector<ll> cnt(n + 1);
        ll ans = 0;

        for(int init : G[o]){
            vector<int> color;
            queue<tuple<int,int,int>> que;
            que.push({init, o, 1});

            while(!que.empty()){
                auto [v, p, d] = que.front(); que.pop();
                if(d == D / 2){
                    ans += cnt[c[v]];
                    color.push_back(c[v]);
                    continue;
                }
                for(int nv : G[v]){
                    if(nv == p) continue;
                    que.push({nv, v, d + 1});
                }
            }
            for(int cl : color){
                cnt[cl]++;
            }
        }

        cout << ans << endl;
    } else {
        int o1, o2;
        rep(i,n){
            if(dist_s[i] + dist_t[i] != D) continue;

            if(dist_t[i] == D / 2) o1 = i;
            if(dist_t[i] == (D + 1) / 2) o2 = i;
        }

        vector<ll> cnt(n + 1);
        ll ans = 0;
        for(int init : {o1, o2}){
            vector<int> color;
            queue<tuple<int,int,int>> que;
            int other = (init == o1 ? o2 : o1);
            que.push({init, other, 1});
            
            while(!que.empty()){
                auto [v, p, d] = que.front(); que.pop();
                if(d == (D + 1) / 2){
                    ans += cnt[c[v]];
                    color.push_back(c[v]);
                    continue;
                }
                for(int nv : G[v]){
                    if(nv == p) continue;
                    que.push({nv, v, d + 1});
                }
            }
            for(int cl : color){
                cnt[cl]++;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}