#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    bool ng = true;
    rep(i,n){
        if(a[i] > b[i]) ng = false;
    }

    if(ng){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    ll d = 0;
    rep(i,n){
        d += max(0LL, b[i] - a[i]);
    }

    vector<ll> res(n);
    bool ok = false;
    rep(i,n){
        if(b[i] - a[i] >= 0 || ok) res[i] = 1;
        else {
            ll dd = a[i] - b[i];
            ll c = (d + dd - 1) / d + 1;
            res[i] = c;
            ok = true;
        }
    }

    for(ll x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}