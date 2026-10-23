#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = int;
using F = int;
const int INF = 1e9;

S op(S a, S b){ return min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f + x; }
F composition(F f, F g){ return f + g; }
F id(){ return 0; }

bool f(int x){ return (x > 0); }

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    rep(i,n){
        int res = seg.max_right<f>(0);
        cout << res + 1 << " ";
        seg.apply(0, res, -1);
        seg.set(res, INF);
    }
    cout << endl;
    
    return 0;
}