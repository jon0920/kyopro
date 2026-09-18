#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> s(n), c(n);
    rep(i,n) cin >> s[i];
    for(int i = 1; i < n; i++) cin >> c[i];

    ll ans = 0;
    ll sum = 0;
    rep(i,n){
        sum += s[i] - c[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}