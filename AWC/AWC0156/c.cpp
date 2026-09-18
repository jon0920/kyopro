#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> diff;
    rep(i,n - 1) diff.push_back(a[i + 1] - a[i]);
    sort(diff.begin(), diff.end());

    ll ans = 0;
    rep(i,n - k) ans += diff[i];
    cout << ans << endl;
    
    return 0;
}