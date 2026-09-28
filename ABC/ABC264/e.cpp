#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, e;
    cin >> n >> m >> e;
    int source = n + m;
    dsu uf(n + m + 1);
    for(int i = n; i < n + m; i++) uf.merge(i, source);

    vector<pair<int,int>> edge(e);
    rep(i,e){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[i] = {u, v};
    }

    int q;
    cin >> q;
    vector<int> query(q);
    vector<bool> use(e, true);
    rep(i,q){
        cin >> query[i];
        query[i]--;
        use[query[i]] = false;
    }
    reverse(query.begin(), query.end());
    
    rep(i,e){
        if(use[i]) uf.merge(edge[i].first, edge[i].second);
    }

    vector<int> ans;
    for(int x : query){
        int cnt = uf.size(source) - (m + 1);
        ans.push_back(cnt);
        uf.merge(edge[x].first, edge[x].second);
    }

    reverse(ans.begin(), ans.end());

    for(int x : ans) cout << x << endl;

    return 0;
}