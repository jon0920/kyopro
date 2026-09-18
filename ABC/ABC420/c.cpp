#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> mn(n);
    ll sum = 0;
    rep(i,n) mn[i] = min(a[i], b[i]), sum += mn[i];

    while(q--){
        char c; ll x, v;
        cin >> c >> x >> v; x--;
        if(c == 'A'){
            a[x] = v;
            sum += min(a[x], b[x]) - mn[x];
            mn[x] = min(a[x], b[x]);
        }
        else{
            b[x] = v;
            sum += min(a[x], b[x]) - mn[x];
            mn[x] = min(a[x], b[x]);
        }
        cout << sum << endl;
    }
    
    return 0;
}