#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> imos(n + 1);
    rep(i,m){
        ll l, r, w;
        cin >> l >> r >> w;
        l--;
        imos[l] += w;
        imos[r] -= w;
    }
    rep(i,n) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,n){
        if(s[i] < imos[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}