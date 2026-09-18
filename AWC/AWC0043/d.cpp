#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    ll ans = 0;
    rep(i,n){
        ll rsum = sum[n] - sum[i + 1];
        ll rcnt = n - 1 - i;
        ans += rsum - (rcnt * a[i]);
    }
    cout << ans << endl;

    return 0;
}