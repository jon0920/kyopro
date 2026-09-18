#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    
    ll ans = 0;
    if(a < r) ans += (r - a) / m;
    if(a > l) ans += (a - l) / m;
    cout << ans << endl;
    
    return 0;
}