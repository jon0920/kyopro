#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    ll ans = 0;
    rep(i,n){
        if(m <= a[i]) continue;
        ll d = (m - a[i]) / b[i];
        if((m - a[i]) % b[i] != 0) d++;
        ans = max(d, ans);
    }
    cout << ans << endl;

    return 0;
}