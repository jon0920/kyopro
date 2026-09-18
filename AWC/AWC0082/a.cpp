#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll ans = 0;
    rep(_,m){
        int s, p;
        ll d;
        cin >> s >> p >> d;
        if(s == 0) ans += a[p - 1] * d;
        else ans += max(0LL, a[p - 1] - k) * d;
    }
    cout << ans << endl;
    
    return 0;
}