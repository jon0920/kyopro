#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(), a.end());
    ll mn = a[0];

    ll denominater = y - x;
    rep(i,n){
        ll numerator = (a[i] - mn) * y;
        if(numerator % denominater != 0){
            cout << -1 << endl;
            return 0;
        }
        ll d = numerator / denominater;
        if(d > a[i]){
            cout << -1 << endl;
            return 0;           
        }
    }

    ll ans = 0;
    rep(i,n){
            ans += a[i] - (a[i] - a[0]) * y / (denominater);
    }

    cout << ans << endl;

    return 0;
}