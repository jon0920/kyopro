#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll last = 0;
    ll ans = 0;
    rep(i,n){
        ans += max(0LL, a[i] - last);
        last = a[i];
    }

    cout << ans << endl;
    
    return 0;
}