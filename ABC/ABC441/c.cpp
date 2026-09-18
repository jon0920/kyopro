#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    rep(i,n-k) a.pop_back();
    
    ll sum = 0, cnt = 0;
    for(int i = k - 1; i >= 0; i--){
        sum += a[i];
        cnt++;
        if(sum >= x){
            cout << cnt + (n - k) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}