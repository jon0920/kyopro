#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    ans += a[1] * (k / 2);
    k -= (k / 2);
    ans += a[0] * k;
    cout << ans << endl;
    
    return 0;
}