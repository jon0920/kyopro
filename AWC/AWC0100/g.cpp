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

    int q;
    cin >> q;
    rep(i,q){
        int s;
        cin >> s;
        s--;
        cout << uf.size(s) << endl;
    }
    
    return 0;
}