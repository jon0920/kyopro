#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    int r = 0;
    ll weight = 0;
    ll ans = 0, sum = 0;
    for(int l = 0; l < n; l++){
        while(r < n && weight + b[r] <= k){
            sum += a[r];
            weight += b[r];
            r++;
        }
        ans = max(ans, sum);
        sum -= a[l];
        weight -= b[l];
    }

    cout << ans << endl;

    return 0;
}