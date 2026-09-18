#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    ll dist = y - x;
    rep(i,n){
        ll wdist = (a[i] - a[0]) * y;
        if(wdist % dist != 0){
            cout << -1 << endl;
            return 0;
        }
        if((wdist / dist) > a[i]){
            cout << -1 << endl;
            return 0;
        }
        ans += a[i] - (wdist / dist);
    }

    cout << ans << endl;

    return 0;
}