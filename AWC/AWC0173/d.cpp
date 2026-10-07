#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> h(m);
    rep(i,m) cin >> h[i];
    vector<ll> imos(m + 1);
    rep(i,n){
        ll l, r, a;
        cin >> l >> r >> a;
        l--;
        imos[l] += a;
        imos[r] -= a;
    }
    rep(i,m) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,m){
        if(h[i] - imos[i] <= 0) ans++;
    }

    cout << ans << endl;
    
    return 0;
}