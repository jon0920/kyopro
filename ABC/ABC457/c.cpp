#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    k--;
    vector<vector<ll>> a(n);
    rep(i,n){
        ll l;
        cin >> l;
        a[i].resize(l);
        rep(j,l) cin >> a[i][j];
    }
    vector<pair<ll,ll>> c(n);
    rep(i,n){
        ll C;
        cin >> C;
        ll sz = a[i].size();
        c[i] = {sz, C};
    }

    ll nxt = 0;
    ll prev;
    ll id;
    rep(i,n){
        prev = nxt;
        nxt += c[i].first * c[i].second;
        if(nxt > k){
            id = i;
            break;
        }
    }

    cout << a[id][(k - prev) % (ll)a[id].size()] << endl;

    return 0;
}