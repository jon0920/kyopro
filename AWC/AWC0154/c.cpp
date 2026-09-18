#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<ll> imos(n + 1);
    rep(i,q){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l] += k;
        imos[r] -= k;
    }
    rep(i,n) imos[i + 1] += imos[i];

    rep(i,n){
        cout << imos[i] + c[i] << " ";
    }
    cout << endl;
    
    return 0;
}