#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> p(n), a(n), b(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    ll mx = -1e9;
    ll sum = 0;
    rep(i,n){
        sum += a[i] - b[i];
        mx = max(mx, (p[i] - b[i]) - (a[i] - b[i]));
    }

    cout << sum + mx << endl;

    return 0;
}