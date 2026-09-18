#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    rep(i,n){
        int it = lower_bound(a.begin(), a.end(), a[i] + m) - a.begin();
        ans = max(ans, it - i);
    }
    cout << ans << endl;
    
    return 0;
}