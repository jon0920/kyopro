#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint;

int main(){
    
    ll n, l, t;
    cin >> n >> l >> t;
    mint::set_mod(l * 2);
    rep(i,n){
        ll x, v;
        cin >> x >> v;
        mint d = x + v * t;
        ll tmp = d.val();
        ll ans = min(tmp, l * 2 - tmp);
        cout << ans << endl;
    }
    
    return 0;
}