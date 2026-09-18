#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<vector<int>> vec(n);
    rep(i,n) vec[i].push_back(i);

    dsu uf(n);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(!uf.same(u, v)){
                int x = uf.leader(u), y = uf.leader(v);
                vector<int> nxt;
                for(auto i : vec[x]) nxt.push_back(i);
                for(auto i : vec[y]) nxt.push_back(i);
                sort(nxt.rbegin(), nxt.rend());
                if(nxt.size() > 10) nxt.resize(10);

                int z = uf.merge(u, v);
                vec[z] = nxt;
            }
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int i = uf.leader(v);
            if(vec[i].size() < k) cout << -1 << endl;
            else cout << vec[i][k - 1] + 1 << endl;
        }
    }

    return 0;
}