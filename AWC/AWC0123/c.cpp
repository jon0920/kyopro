#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> G(n);
    for(ll i = 1; i < n; i++){
        ll p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    b[0] = 0;

    ll sum = 0;
    auto dfs = [&](auto dfs, int x) -> void {
        ll cnt = 0;
        for(int nx : G[x]){
            dfs(dfs, nx);
            sum += b[nx] * a[nx];
            cnt += b[nx];
        }
        b[x] += cnt;
    };

    dfs(dfs, 0);
    sum += b[0] * a[0];

    cout << sum << endl;
    
    return 0;
}