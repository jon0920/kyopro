#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, d, s;
    cin >> n >> d >> s;
    s--;
    ll sum = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    ll ans = 0;
    for(int i = s; i < n; i++){
        ans += a[i];
        d--;
        if(d == 0) break;
    }

    ans += sum * (d / n);
    d %= n;

    rep(i,n){
        if(d > 0){
            ans += a[i];
            d--;
        } else break;
    }

    cout << ans << endl;
    
    return 0;
}