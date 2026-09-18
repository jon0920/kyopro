#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    ll ans = 0;
    for(auto A : a){
        ans += upper_bound(a.begin(), a.end(), A / 2) - a.begin();
    }

    cout << ans << endl;
    
    return 0;
}