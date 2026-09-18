#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        ll a, t;
        cin >> a >> t;
        ans += a * t;
    }
    cout << ans << endl;
    
    return 0;
}