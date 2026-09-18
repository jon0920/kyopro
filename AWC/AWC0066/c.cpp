#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> w(n);
    rep(i,n) cin >> w[i];
    vector<ll> imos(n + 1);
    while(q--){
        ll l, r, d;
        cin >> l >> r >> d;
        l--;
        imos[l] += d;
        imos[r] -= d;
    }
    rep(i,n) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,n){
        if(w[i] - imos[i] <= 0) ans++;
    }
    cout << ans << endl;

    return 0;
}