#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    ll k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    dsu uf(n);
    rep(i,n - 1){
        if(abs(a[i] - a[i + 1]) <= k) uf.merge(i, i + 1);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(uf.same(l, r)) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }

    return 0;
}