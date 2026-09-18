#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> t(k), p(k);
    rep(i,k) cin >> t[i] >> p[i];
    vector<ll> c(n);
    ll sum = 0;
    rep(i,n){
        cin >> c[i];
        sum += c[i];
    }
    sort(c.rbegin(), c.rend());

    ll ans = sum;
    ll x = 0;
    rep(i,n){
        x += c[i];
        sum -= c[i];
        int it = upper_bound(t.begin(), t.end(), x) - t.begin();
        it--;
        ll y = x - ((x * p[it]) / 100);
        ans = min(ans, y + sum);
    }

    cout << ans << endl;
    
    return 0;
}