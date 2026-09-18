#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    dsu uf(n);

    bool ans = true;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(uf.same(a, b)) ans = false;
        uf.merge(a, b);
        deg[a]++, deg[b]++;
    }

    for(auto x : deg) if(x > 2) ans = false;
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}