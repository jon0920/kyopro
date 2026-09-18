#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> c(k);
    rep(i,k) cin >> c[i], c[i]--;

    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> cnt(n);
    vector<bool> check(n);
    queue<int> que;
    for(auto x : c){
        check[x] = true;
        que.push(x);
    }

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(check[nv]) continue;
            cnt[nv]++;
            if(cnt[nv] >= t){
                que.push(nv);
                check[nv] = true;
            }
        }
    }

    int ans = 0;
    for(auto x : check) if(x) ans++;
    cout << ans << endl;

    return 0;
}