#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll mx = *max_element(a.begin(), a.end());
    ll ans = mx - a[0];
    for(int i = 1; i < n; i++) ans += max(0LL, a[i - 1] - a[i]);

    cout << ans << endl;
    
    return 0;
}