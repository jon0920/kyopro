#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> p(m);
    rep(i,m){
        ll l, r;
        cin >> l >> r;
        p[i] = {l, r};
    } 
    sort(p.begin(), p.end());
    
    ll cur = 0;
    for(auto [l, r] : p){
        if(cur < l){
            ll len = l - cur - 1;
            if(n <= len){
                cout << cur + n << endl;
                return 0;
            }
            n -= len;
        }
        cur = max(cur, r);
    }

    cout << cur + n << endl;

    return 0;
}