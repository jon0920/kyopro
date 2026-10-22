#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    ll n;
    cin >> n;
    
    mint ans = mint(n) * mint(n - 1) / 2;
    ll l = 1;
    while(l < n + 1){
        ll q = n / l;
        ll r = n / q;
        ans -= (q - 1) * (r - l + 1);
        l = r + 1;
    }

    cout << ans.val() << endl;
    
    return 0;
}