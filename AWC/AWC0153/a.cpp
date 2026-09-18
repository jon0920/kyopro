#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(k);
    rep(i,k) cin >> b[i];
    vector<ll> c(k);
    rep(i,k) cin >> c[i];

    rep(i,k){
        a[b[i] - 1] = c[i];
    }

    ll ans = 0;
    rep(i,n - 1){
        ans += abs(a[i + 1] - a[i]);
    }
    cout << ans << endl;
    
    return 0;
}