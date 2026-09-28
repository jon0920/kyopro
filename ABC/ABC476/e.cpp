#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<int,int>;
const int INF = 1e9;

P min_op(P a, P b){
    if(a.first < b.first) return a;
    return b;
}
P min_e(){
    return {INF, -1};
}

P max_op(P a, P b){
    if(a.first > b.first) return a;
    return b;
}

P max_e(){
    return {-INF, -1};
}

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> p(n);
    rep(i,n){
        cin >> p[i].first;
        p[i].second = i;
    }

    segtree<P, min_op, min_e> min_seg(p);
    segtree<P, max_op, max_e> max_seg(p);

    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        pair<int,int> mn = min_seg.prod(l, r);
        pair<int,int> mx = max_seg.prod(l, r);

        min_seg.set(mn.second, {mx.first, mn.second});
        max_seg.set(mn.second, {mx.first, mn.second});
    
        min_seg.set(mx.second, {mn.first, mx.second});
        max_seg.set(mx.second, {mn.first, mx.second});
    }

    rep(i,n){
        cout << min_seg.get(i).first << " ";
    }
    cout << endl;
    
    return 0;
}