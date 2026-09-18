#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    rep(i,n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<ll> cnt(mx + 1);
    rep(i,n) cnt[a[i]]++;

    vector<ll> sum(mx + 2);
    rep(i,mx + 1) sum[i + 1] = sum[i] + cnt[i];

    ll ans = 0;
    for(ll x = 1; x <= mx; x++){
        if(cnt[x] >= 2) ans += cnt[x] * (cnt[x] - 1) / 2;
    }
    
    for(ll x = 1; x <= mx; x++){
        if(cnt[x] == 0) continue;
        for(ll k = 1; k * x <= mx; k++){
            ll L = k * x;
            ll R = min(mx + 1, (k + 1) * x);
            if(k == 1) L = x + 1;
            if(L >= R) continue;
            ans += cnt[x] * (sum[R] - sum[L]) * k;
        }
    }

    cout << ans << endl;
    
    return 0;
}