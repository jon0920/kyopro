#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,m){
        ll b, s;
        cin >> b >> s;
        ans += a[--b];
        ans += s;
    }

    cout << ans << endl;

    return 0;
}