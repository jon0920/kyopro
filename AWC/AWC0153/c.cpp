#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m; ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> imos(n + 1);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
    }

    rep(i,n) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,n){
        if(a[i] + imos[i] >= k) ans++;
    }
    cout << ans << endl;
    
    return 0;
}