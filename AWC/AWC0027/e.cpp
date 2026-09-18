#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int r = 0;
    ll sum = 0, pcnt = 0, cnt = 0;
    ll ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n && sum <= k){
            sum += a[r];
            cnt = (r - l + 1) * m;
            sum += cnt - pcnt;
            pcnt = cnt;
            r++;
        }
        ans += r - l - 1;
        sum -= a[l];
    }

    cout << ans << endl;

    return 0;
}