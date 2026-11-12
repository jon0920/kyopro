#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint;

int main(){
    
    ll n, p;
    cin >> n >> p;
    modint::set_mod(p);

    mint ans = 1;
    rep(i,n){
        ll a;
        cin >> a;
        ans *= mint(a);
    }

    cout << ans.val() << endl;
    
    return 0;
}