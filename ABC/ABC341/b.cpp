#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n - 1){
        ll s, t;
        cin >> s >> t;
        a[i + 1] += (a[i] / s) * t;
    }
    cout << a[n - 1] << endl;
    
    return 0;
}