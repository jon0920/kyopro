#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(j,m) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = -1;
    rep(i,n){
        int it = upper_bound(b.begin(), b.end(), a[i] + d) - b.begin();
        it--;
        if(abs(a[i] - b[it]) <= d) ans = max(ans, a[i] + b[it]);
    }
    cout << ans << endl;
    
    return 0;
}