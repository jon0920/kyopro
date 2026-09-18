#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, s, k;
    cin >> n >> s >> k;
    s--;
    vector<ll> a(n), sum(n + 1);
    rep(i,n){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    ll ans = 0;
    for(int l = 0; l <= s; l++){
        if(s - l > k) continue;
        ll r1 = k - s + 2 * l; // (s - l) + (r - l) <= k
        ll r2 = (k + s + l) / 2; // (r - s) + (r - l) <= k
        ll r = max(r1, r2);
        r = min(r, (ll)n - 1);
        ans = max(ans, sum[r + 1] - sum[l]);
    }

    cout << ans << endl;
    
    return 0;
}