#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    
    ll p = sum / n;
    ll r = sum % n;
    ll ans = 0;
    rep(i,n){
        if(i < r){
            ans += max(0LL, a[i] - (p + 1));
        } else {
            ans += max(0LL, a[i] - p);
        }
    }

    cout << ans << endl;
    
    return 0;
}