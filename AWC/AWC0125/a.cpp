#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, d, s;
    cin >> n >> d >> s;
    s--;
    vector<ll> t(n);
    ll ans = 0;
    rep(i,n){
        cin >> t[i];
        ans += t[i];
    }

    ll x = min(s, n - 1 - s);
    ans += (n - 1 + x) * d;
    cout << ans << endl;
    
    return 0;
}