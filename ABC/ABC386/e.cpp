#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll base = 0;
    if(k > n - k){
        for(ll x : a) base ^= x;
    }

    ll ans = 0;
    auto dfs = [&](auto dfs, int start, int rest, ll cur) -> void {
        if(rest == 0){
            ans = max(ans, base ^ cur);
            return;
        }
        for(int i = start; i <= n - rest; i++){
            dfs(dfs, i + 1, rest - 1, cur ^ a[i]);
        }
    };

    dfs(dfs, 0, min(k, n - k), 0);

    cout << ans << endl;
    
    return 0;
}