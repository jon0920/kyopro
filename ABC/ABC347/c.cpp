#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, a, b;
    cin >> n >> a >> b;
    ll w = a + b;
    vector<ll> r(n);
    rep(i,n){
        ll d;
        cin >> d;
        r[i] = d % w;
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    int m = r.size();

    bool ok = false;
    if(m == 1) ok = true;
    rep(i,m){
        ll x = r[i], y = r[(i + 1) % m];
        if(((y - x + w) % w) > b) ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}