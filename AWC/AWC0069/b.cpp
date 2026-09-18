#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n){
        ll t, c;
        cin >> t >> c;
        v[i] = t + c;
    }
    sort(v.rbegin(), v.rend());

    ll ans = 0;
    rep(i,k) ans += v[i];
    cout << ans << endl;
    
    return 0;
}