#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    bool ok = true;
    int ans = 0;
    dsu uf(n * 2);
    vector<int> cnt(n * 2);
    rep(i,n) cnt[i] = 1;

    auto MERGE = [&](int u, int v) -> void {
        int ru = uf.leader(u);
        int rv = uf.leader(v);
        if(ru == rv) return;

        int tot = cnt[ru] + cnt[rv];
        int r = uf.merge(ru, rv);
        cnt[r] = tot;
    };

    auto cost = [&](int u) {
        return min(cnt[uf.leader(u)], cnt[uf.leader(u + n)]);
    };

    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;

        if(!ok){
            cout << -1 << endl;
            continue;
        }

        bool is_same = uf.same(u, v) || uf.same(u, v + n);
        if(!is_same){
            ans -= cost(u);
            ans -= cost(v);
        }

        MERGE(u, v + n);
        MERGE(u + n, v);
        if(uf.same(u, u + n)) ok = false;

        if(!is_same && ok) ans += cost(u);
        
        cout << (ok ? ans : -1) << endl;
    }
    
    return 0;
}