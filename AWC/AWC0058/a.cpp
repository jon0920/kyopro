#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

int main(){

    ll n, p, t, c;
    cin >> n >> p >> t >> c;
    vector<ll> s(n - 1);
    rep(i,n - 1) cin >> s[i];
    sort(s.rbegin(), s.rend());

    if(p >= t) cout << 0 << endl;
    else if(s.empty() || s[0] < t) cout << -1 << endl;
    else cout << c << endl;

    return 0;
}