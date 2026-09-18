#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll sum = reduce(a.begin(), a.end());
    ll ans = 0;
    rep(i,n){
        sum -= a[i];
        ans += a[i] * sum;
    }

    cout << ans << endl;
    
    return 0;
}