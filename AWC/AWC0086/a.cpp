#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, xa, ya, r;
    cin >> n >> xa >> ya >> r;
    ll ans = 0;
    rep(i,n){
        ll x, y, p;
        cin >> x >> y >> p;
        if((xa - x) * (xa - x) + (ya - y) * (ya - y) <= r * r) ans += p;
    }
    cout << ans << endl;
    
    return 0;
}