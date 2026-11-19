#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    ll ans = -1e18;
    ll mn = 0;
    ll sum = 0;
    rep(i,n){
        sum += v[i];
        ans = max(ans, sum - mn);
        mn = min(mn, sum);
    }

    cout << ans << endl;
    
    return 0;
}