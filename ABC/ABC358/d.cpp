#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int apos = 0, bpos = 0;
    ll ans = 0;
    while(bpos < m && apos < n){
        if(a[apos] >= b[bpos]){
            ans += a[apos];
            apos++;
            bpos++;
        }
        else apos++;
    }
    
    if(bpos < m) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}