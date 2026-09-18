#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> g(m);
    rep(i,m) cin >> g[i];

    fenwick_tree<int> fw(n + 1);
    ll ans = 0;
    for(int i = m - 1; i >= 0; i--){
        ans += fw.sum(0, g[i]);
        fw.add(g[i], 1);
    }

    cout << ans << endl;

    return 0;
}