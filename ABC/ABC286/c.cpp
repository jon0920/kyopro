#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    ll a, b;
    string s;
    cin >> n >> a >> b >> s;

    ll ans = 1e18;
    rep(i,n){
        ll sum = i * a;
        rep(j,n/2){
            if(s[j] != s[n - j - 1]) sum += b;
        }
        ans = min(ans, sum);
        s = s.substr(1) + s[0];
    }
    cout << ans << endl;
    
    return 0;
}