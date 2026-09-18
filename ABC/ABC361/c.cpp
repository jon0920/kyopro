#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 1e18;
    rep(i,k+1){
        ll cur = a[i + n - k - 1] - a[i];
        ans = min(cur, ans);
    }

    cout << ans << endl;
    
    return 0;
}