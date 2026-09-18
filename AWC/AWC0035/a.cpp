#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];

    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        p[u] -= w;
        p[v] += w;
    }

    int ans;
    ll mx = 0;
    rep(i,n){
        if(mx < p[i]){
            ans = i + 1;
            mx = p[i];
        }
    }
    cout << ans << endl;

    return 0;
}