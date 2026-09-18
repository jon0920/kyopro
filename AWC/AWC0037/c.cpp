#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

mint op(mint a, mint b){ return a * b; }
mint e(){ return 1; }

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<mint> A(n);
    rep(i,n){
        cin >> a[i];
        A[i] = a[i];
    }
    segtree<mint, op, e> seg(A);

    mint ans = 0;
    rep(i,n-k+1){
        ans += seg.prod(i, i + k);
    }
    cout << ans.val() << endl;

    return 0;
}