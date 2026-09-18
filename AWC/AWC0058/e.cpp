#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

const int INF = 1e9;
P op(P a, P b){ return {min(a.first, b.first), max(a.second, b.second)}; }
P e(){ return {INF, -INF}; }

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> p(n);
    rep(i,n){
        int a;
        cin >> a;
        p[i] = {a, a};
    }

    segtree<P, op, e> seg(p);

    int r = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n){
            P res = seg.prod(l, r + 1);
            if(res.second - res.first <= k) r++;
            else break;
        }
        ans = max(ans, r - l);
        if(r == l) r++;
    }
    cout << ans << endl;

    return 0;
}