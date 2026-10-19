#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }

    set<pair<int,int>> st;
    int k;
    cin >> k;
    rep(i,k){
        int x, y;
        cin >> x >> y;
        x--, y--;
        int rx = uf.leader(x);
        int ry = uf.leader(y);
        if(rx > ry) swap(rx, ry);
        st.insert({rx, ry});
    }

    int Q;
    cin >> Q;
    while(Q--){
        int p, q;
        cin >> p >> q;
        p--, q--;
        int rp = uf.leader(p);
        int rq = uf.leader(q);
        if(rp > rq) swap(rp, rq);

        if(st.count({rp, rq})) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    
    return 0;
}