#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, t;
    cin >> n >> t;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    ll ans = 0;
    rep(i,n){
        ans += max(a[i] - b[i] * t, 0LL);
    }
    cout << ans << endl;

    return 0;
}