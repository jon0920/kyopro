#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    while(q--){
        ll x;
        cin >> x;
        int it = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll ans = 0;
        ans += (sum[n] - sum[it]) - x * (n - it);
        ans += it * x - sum[it];
        cout << ans << endl; 
    }

    return 0;
}