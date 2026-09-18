#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n), d(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> d[i];
    sort(a.rbegin(), a.rend());
    sort(d.rbegin(), d.rend());

    int apos = 0, dpos = 0;
    ll ans = 0;
    while(apos < n && dpos < m){
        if(a[apos] >= d[dpos]){
            ans += (a[apos] - d[dpos]);
            apos++; dpos++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}