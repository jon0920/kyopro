#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

using P = pair<int,int>;
P op(P a, P b){
    vector<int> v = {a.first, a.second, b.first, b.second};
    sort(v.rbegin(), v.rend());
    v.erase(unique(v.begin(), v.end()), v.end());
    return {v[0], v[1]};
}
P e(){ return {-INF, -INF}; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<P> vec(n);
    rep(i,n){
        int a;
        cin >> a;
        vec[i] = {a, -INF};
    }

    segtree<P, op, e> seg(vec);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int p, x;
            cin >> p >> x;
            p--;
            seg.set(p, {x, -INF});        
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            auto [x, y] = seg.prod(l, r);
            if(y <= -1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}