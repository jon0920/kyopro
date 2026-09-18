#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    rep(i,k) a[i] /= 2;

    ll ans = 0;
    for(auto x : a) ans += x;
    cout << ans << endl;

    return 0;
}