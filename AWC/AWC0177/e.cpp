#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, a, b;
    cin >> n >> a >> b;
    vector<pair<ll,ll>> pts(n);
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    sort(pts.begin(), pts.end());

    auto calc = [&](ll c, bool strict) -> ll {
        vector<ll> z(n);
        rep(i,n){
            auto [x, y] = pts[i];
            z[i] = y - c * x;
        }

        vector<ll> values = z;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int sz = values.size();
        fenwick_tree<int> fw(sz);

        ll res = 0;
        for(ll val : z){
            int rank = lower_bound(values.begin(), values.end(), val) - values.begin();

            res += fw.sum(rank + (strict ? 1 : 0), sz);
            fw.add(rank, 1);
        }

        return res;
    };

    cout << calc(b, false) - calc(a, true) << endl;
    
    return 0;
}