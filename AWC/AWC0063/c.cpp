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
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    mint mx = 0, total = 0;
    for(ll x : s) total += x;
    mx = *max_element(s.begin(), s.end());

    mint ans = (total - mx) + mx * mint(2).pow(k);
    cout << ans.val() << endl;

    return 0;
}