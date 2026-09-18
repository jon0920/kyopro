#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edge(m);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[i] = {u, v};
    }

    vector<vector<int>> G(n);
    dsu uf(n);
    for(auto [u, v] : edge){
        if(uf.same(u, v)){
            cout << "No" << endl;
            return 0;
        }
        uf.merge(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int end_cnt = 0;
    for(auto v : G){
        if(v.size() == 1) end_cnt++;
        else if(v.size() != 2){
            cout << "No" << endl;
            return 0;
        }
    }

    if(end_cnt == 2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}