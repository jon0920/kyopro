#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m;
    cin >> n >> m;
    vector<set<int>> a(n);
    rep(i,m){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].insert(y);
        a[y].insert(x);
    }

    rep(i,n){
        ll r = n - a[i].size() - 1;
        ll ans = r * (r - 1) * (r - 2);
        ans /= 6;
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}