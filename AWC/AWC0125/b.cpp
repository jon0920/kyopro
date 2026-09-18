#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, d, k;
    cin >> n >> m >> d >> k;
    vector<ll> a(n);
    rep(i,n){
        ll x;
        cin >> x;
        a[i] = max(0LL, x - m * d);
    }
    
    sort(a.rbegin(), a.rend());
    rep(i,min(m,k)) a[i] = 0;

    int ans = 0;
    rep(i,n) if(a[i] >= 1) ans++;
    cout << ans << endl;
    
    return 0;
}