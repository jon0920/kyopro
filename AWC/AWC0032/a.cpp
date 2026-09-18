#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, r;
    cin >> n >> r;
    int ans = 0;
    rep(i,n){
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        if((x - p) * (x - p) + (y - q) * (y - q) <= r * r) ans++;
    }
    cout << ans << endl;

    return 0;
}