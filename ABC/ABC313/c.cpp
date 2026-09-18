#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> target(n, sum / n);
    int r = sum % n;
    for(int i = 0; i < r; i++){
        target[n - 1 - i]++;
    }

    ll ans = 0;
    rep(i,n) ans += (abs(a[i] - target[i]));
    ans /= 2;
    cout << ans << endl;
    
    return 0;
}