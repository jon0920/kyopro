#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];

    sort(x.begin(), x.end());
    vector<ll> dist(n - 1);
    rep(i,n){
        dist[i] = x[i + 1] - x[i];
    }
    sort(dist.begin(), dist.end());

    ll ans = 0;
    rep(i,n-m) ans += dist[i];
    cout << ans << endl;
    
    return 0;
}