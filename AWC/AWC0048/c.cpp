#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    
    vector<ll> imos(n + 1);
    rep(i,m){
        ll l, r, d;
        cin >> l >> r >> d;
        l--;
        imos[l] += d;
        imos[r] -= d;
    }
    rep(i,n) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,n){
        if(h[i] - imos[i] >= 1) ans++;
    }
    
    cout << ans << endl;

    return 0;
}