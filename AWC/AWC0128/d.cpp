#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> f(n);
    rep(i,n) cin >> f[i];

    vector<ll> imos(n + 1);
    rep(i,m){
        int l, r; ll d;
        cin >> l >> r >> d;
        l--;
        imos[l] += d;
        imos[r] -= d;
    }
    rep(i,n) imos[i + 1] += imos[i];

    rep(i,n){
        f[i] = max(0LL, f[i] - imos[i]);
    }
    
    int ans = 0;
    rep(i,n) if(f[i] <= t) ans++;

    cout << ans << endl;
    
    return 0;
}