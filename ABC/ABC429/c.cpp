#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    int a;
    vector<ll> f(n);
    rep(i,n){
        cin >> a;
        f[a - 1]++;
    }
    
    ll ans = 0;
    rep(i,n){
        ans += f[i] * (f[i] - 1) / 2 * (n - f[i]);
    }
    cout << ans << endl;
    return 0;
}