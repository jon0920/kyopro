#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

using P = pair<int,int>;
P op(P a, P b){
    return {min(a.first, b.first), max(a.second, b.second)};
}
P e(){ return {INF, -INF}; }

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> H(n);
    rep(i,n){
        int h;
        cin >> h;
        H[i] = {h, h};
    }

    segtree<P, op, e> seg(H);
    int ans = 0;
    for(int i = 0; i < n - k + 1; i++){
        int d = seg.prod(i, i + k).second - seg.prod(i, i + k).first;
        ans = max(ans, d);
    }
    cout << ans << endl;
    
    return 0;
}