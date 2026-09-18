#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k, q, t;
    cin >> n >> m >> k >> q >> t;
    t--;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> s(k);
    set<int> st;
    rep(i,k) cin >> s[i], s[i]--;
    rep(i,q){
        int p;
        cin >> p;
        p--;
        st.insert(p);
    }

    queue<int> que;
    que.push(t);
    vector<int> dist(n, -1);
    dist[t] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(st.count(nv)) continue;
            if(dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    int ans = 0;
    for(auto x : s){
        if(dist[x] == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, dist[x]);
    }
    cout << ans << endl;
    
    return 0;
}