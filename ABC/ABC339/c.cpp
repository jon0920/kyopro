#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n);
    ll ans = 0;
    rep(i,n){
        cin >> a[i];
        ans += a[i];
        sum[i] = ans;
    }
    ll mn = 0;
    rep(i,n){
        mn = min(mn, sum[i]);
    }
    cout << ans - mn << endl;
    
    return 0;
}