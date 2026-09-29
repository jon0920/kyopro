#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll mx = 0, mn = 1e18;
    vector<bool> seen(n);
    rep(i,n){
        if(!seen[i]){
            seen[i] = true;
            queue<int> que;
            que.push(i);
            ll sum = p[i];
            ll cnt = 1;
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(int nv : G[v]){
                    if(!seen[nv]){
                        seen[nv] = true;
                        cnt++;
                        sum += p[nv];
                        que.push(nv);
                    }
                }
            }
            mx = max(mx, (sum + cnt - 1) / cnt);
            mn = min(mn, sum / cnt);
        }
    }

    cout << mx - mn << endl;
    
    return 0;
}