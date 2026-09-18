#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];

    mint sum = 0;
    mint mx = *max_element(l.begin(), l.end());
    for(auto x : l){
        sum += x;
    }

    mint ans = (sum - mx) + mx * mint(2).pow(k);
    cout << ans.val() << endl;

    return 0;
}