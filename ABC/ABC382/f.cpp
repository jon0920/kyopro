#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)


using S = int;
using F = int;
const S INF = 1e9;

S op(S a, S b){ return max(a, b); }
S e(){ return 0; }
S mapping(F f, S x) { return (f == INF ? x : f); }
F composition(F f, F g){ return (f == INF ? g : f); }
F id(){ return INF; }

int main(){
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<tuple<int,int,int,int>> blocks(n);
    rep(i,n){
        int r, c, l;
        cin >> r >> c >> l;
        c--;
        blocks[i] = {r, c, l, i};
    }
    sort(blocks.rbegin(), blocks.rend());

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(w);

    vector<int> ans(n);
    for(auto [r, c, l, id] : blocks){
        int mx = seg.prod(c, c + l);
        ans[id] = h - mx;
        seg.apply(c, c + l, mx + 1);
    }

    for(int x : ans) cout << x << endl;
    
    return 0;
}