#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    sort(x.begin(), x.end());

    ll p = x[(n - 1) / 2];
    ll ans = 0;
    for(auto d : x) ans += abs(d - p);
    cout << ans << endl;

    return 0;
}