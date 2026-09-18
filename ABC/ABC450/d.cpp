#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    ll mx = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for(auto &x : a){
        if(mx == x) continue;
        ll r = (mx - x) / k;
        x += r * k;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    ll ans = a[n - 1] - a[0];
    rep(i,n - 1){
        a[i] += k;
        ans = min(ans, a[i] - a[i + 1]);
    }
    cout << ans << endl;

    return 0;
}