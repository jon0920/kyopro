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
    dsu uf(n);
    dsu uf2(n * 2);
    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(!uf.same(u, v)){
            ans -= uf.size(uf.leader(u)) / 2;
            ans -= uf.size(uf.leader(v)) / 2;

            uf.merge(u, v);
            uf2.merge(u, v + n);
            uf2.merge(u + n, v);
            if(uf2.same(u, u + n)) ok = false;

            ans += uf.size(uf.leader(u)) / 2;
        } else {
            uf2.merge(u, v + n);
            uf2.merge(u + n, v);
            if(uf2.same(u, u + n)) ok = false;
        }
        cout << (ok ? ans : -1) << endl;
    }
    
    return 0;
}