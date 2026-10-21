#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int MAX = 500100;
int op(int a, int b){ return max(a, b); }
int e(){ return 0; }

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    segtree<int, op, e> seg(MAX);
    int ans = 0;
    rep(i,n){
        int l = max(0, a[i] - d);
        int r = min(MAX, a[i] + d + 1);

        int res = seg.prod(l, r) + 1;
        ans = max(ans, res);
        seg.set(a[i], res);
    }

    cout << ans << endl;
    
    return 0;
}