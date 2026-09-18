#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return max(a, b); }
int e(){ return 0; }

int main(){

    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    segtree<int, op, e> seg(h);
    vector<int> ans;
    rep(i,n){
        int r = seg.max_right(i, [&](int x){return x <= h[i];});
        int l = seg.min_left(i, [&](int x){return x <= h[i];});
        ans.push_back(r - l);
    }
    sort(ans.begin(), ans.end());

    while(q--){
        int x;
        cin >> x;
        cout << (ans.end() - lower_bound(ans.begin(), ans.end(), x)) << endl;
    }

    return 0;
}