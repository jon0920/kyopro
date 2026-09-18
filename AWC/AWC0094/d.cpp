#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){
    
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll p = a * b * c;
    mint ans = 1;
    for(ll i = 0; i < n; i++){
        ans *= (p - i);
    }

    cout << ans.val() << endl;
    
    return 0;
}