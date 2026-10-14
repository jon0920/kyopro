#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

ll op(ll a, ll b){ return max(a, b); }
ll e(){ return 0; }

int main(){
    
    int n;
    cin >> n;
    vector<pair<ll,ll>> edges(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }

    sort(edges.begin(), edges.end(), [](const auto &x, const auto &y){
        if(x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    auto LIS = [&](vector<ll> v) -> ll {
        int sz = v.size();
        vector<pair<int,int>> sort_v(sz);
        rep(i,sz){
            sort_v[i] = {v[i], i};
        }
        sort(sort_v.begin(), sort_v.end(), [](const auto &x, const auto &y){
            if(x.first != y.first) return x.first < y.first;
            return x.second > y.second;
        });

        segtree<ll, op, e> seg(sz);
        for(auto [x, id] : sort_v){
            int mx = seg.prod(0, id);
            seg.set(id, mx + 1);
        }

        return seg.prod(0, sz);
    };

    vector<ll> B(n);
    rep(i,n) B[i] = edges[i].second;

    cout << LIS(B) << endl;
    
    return 0;
}