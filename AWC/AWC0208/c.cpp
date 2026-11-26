#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(v.rbegin(), v.rend());

    ll ans = 0;
    rep(i,n){
        if(i % m == 0) ans += v[i];
    }
    cout << ans << endl;
    
    return 0;
}