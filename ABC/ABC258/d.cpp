#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main(){

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    ll ans = (ll)4e18;
    ll sum = 0;
    rep(i,n){
        if(i + 1 > x) break;
        sum += a[i] + b[i];
        ans = min(ans, sum + b[i] * (x - i - 1));
    }

    cout << ans << endl;

    return 0;
}