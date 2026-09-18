#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll x; ll y; ll r;
};

int main(){
    
    int n;
    cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int s = -1, t = -1;
    vector<S> circles(n);
    rep(i,n){
        ll x, y, r;
        cin >> x >> y >> r;
        circles[i] = {x, y, r};
        if(s == -1){
            ll dx = (sx - x) * (sx - x);
            ll dy = (sy - y) * (sy - y);
            if(r * r == dx + dy) s = i;
        }
        if(t == -1){
            ll dx = (tx - x) * (tx - x);
            ll dy = (ty - y) * (ty - y);
            if(r * r == dx + dy) t = i;
        }
    }


    atcoder::dsu uf(n);

    auto check = [&](int p, int q){
        auto [px, py, pr] = circles[p];
        auto [qx, qy, qr] = circles[q];
        ll d = (px - qx) * (px - qx) + (py - qy) * (py - qy);
        ll rd = (pr - qr) * (pr - qr);
        ll rs = (pr + qr) * (pr + qr);
        return (rd <= d && d <= rs);
    };

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(check(i, j)) uf.merge(i,j);
        }
    }

    if(uf.leader(s) == uf.leader(t)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}