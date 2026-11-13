#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] -= c;
    }
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    ll mn = 0;
    ll ans = 0;
    rep(i,n){
        mn = min(mn, sum[i + 1]);
        ans = max(ans, sum[i + 1] - mn);
    }

    cout << ans << endl;
    
    return 0;
}