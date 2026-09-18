#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), s(n + 1);
    rep(i,n){
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    ll sum = 0;
    for(ll i = 0; i < m; i++){
        sum += a[i] * (i + 1);
    }
    ll ans = sum;
    rep(i,n-m){
        sum += a[i + m] * m;
        sum -= s[i + m] - s[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}