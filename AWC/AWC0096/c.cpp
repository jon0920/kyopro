#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<int> d(n);
    rep(i,n){
        d[i] = b[i] - a[i];
        if(d[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    ll crr = 0;
    ll ans = 0;
    vector<ll> cnt(n), res(n);
    rep(i,n){
        crr -= cnt[i];
        ll dist = d[i] - crr;
        if(dist < 0){
            cout << -1 << endl;
            return 0;
        }
        if(dist > 0 && i + k > n){
            cout << -1 << endl;
            return 0;
        }
        if(i + k < n) cnt[i + k] = dist;
        crr += dist;
        ans += dist;
        res[i] = crr;
    }

    cout << ans << endl;
    
    return 0;
}