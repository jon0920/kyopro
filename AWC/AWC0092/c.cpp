#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    
    int ans = k;
    vector<bool> check(n);
    queue<int> que;
    rep(i,k){
        int s;
        cin >> s;
        s--;
        check[s] = true;
        que.push(s);
    }
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(!check[nv]){
                check[nv] = true;
                que.push(nv);
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}