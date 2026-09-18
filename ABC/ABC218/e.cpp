#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,ll>> abc(m);
    rep(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        abc[i] = {a, b, c};
    }
    sort(abc.begin(), abc.end(), [](const auto &x, const auto &y){
        auto [ax, bx, cx] = x;
        auto [ay, by, cy] = y;
        return cx < cy;
    });

    dsu uf(n);
    ll ans = 0;
    for(auto [a, b, c] : abc){
        if(uf.same(a, b)){
            if(c > 0) ans += c;
        } else {
            uf.merge(a, b);
        }
    }

    cout << ans << endl;

    return 0;
}