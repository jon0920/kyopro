#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    vector<vector<int>> G(n);
    vector<int> load(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        load[v]++;
    }

    vector<bool> num(n);
    queue<int> que;
    rep(i,n) if(load[i] > t[i]){
        num[i] = true;
        que.push(i);
    }

    if(que.empty()){
        cout << -1 << endl;
        return 0;
    }

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(num[nv]) continue;
            load[nv]++;
            if(load[nv] > t[nv]){
                num[nv] = true;
                que.push(nv);
            }
        }
    }

    rep(i,n) if(num[i]) cout << i + 1 << " ";
    cout << endl;

    return 0;
}