#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;

    ll ans = 0;
    vector<ll> num(n + 1, 0);
    for(ll x = 1; x <= n; x++){
        for(ll y = 1; x * y <= n; y++){
            num[x * y]++;
        }
    }

    for(ll v = 1; v <= n; v++){
        ans += num[v] * num[n - v];
    }
    
    cout << ans << endl;
    
    return 0;
}