#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m;
    cin >> n >> m;
    vector<ll> x(m), a(m);
    ll sum = 0;
    rep(i,m) cin >> x[i];
    rep(i,m) cin >> a[i], sum += a[i];    
    if(sum != n){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<ll,ll>> xa(m);
    rep(i,m){
        xa[i] = {x[i], a[i]};
    }
    sort(xa.rbegin(), xa.rend());

    ll right = n;
    ll ans = 0;
    for(auto [pos, num] : xa){
        ll dist = right - pos;
        if(num > dist){
            if(dist + 1 < num){
                cout << -1 << endl;
                return 0;
            }
            ans += (dist + 1) * dist / 2;
            right = max(right - num, pos) - 1;
        } else {
            ans += (dist + 1) * dist / 2;
            ans -= ((dist - num) + 1) * (dist - num) / 2;
            right -= num;
        }
    }
    
    if(right == 0) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}