#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + m);
    rep(i,n + m) cin >> a[i];
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    rep(i,k) ans += a[i];
    cout << ans << endl;
    
    return 0;
}