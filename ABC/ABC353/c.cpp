#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    int r = n;
    ll cnt = 0, res = 0;
    for(int i = 0; i < n; i++){
        r = max(r, i + 1);
        while(r - 1 > i && a[r - 1] + a[i] >= 100000000) r--;
        cnt += n - r;
    }
    rep(i,n) res += a[i] * (n - 1);
    res -= cnt * 100000000;
    cout << res << endl;
    
    return 0;
}