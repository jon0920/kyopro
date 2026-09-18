#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    sort(a.rbegin(), a.rend());

    int pos = 0;
    while(k > 0 && pos < n){
        int cnt = a[pos] / x;
        if(k >= cnt){
            k -= cnt;
            a[pos] %= x;
        }
        else{
            a[pos] -= x * k;
            k = 0;
        }
        pos++;
    }

    if(k > 0){
        sort(a.rbegin(), a.rend());
        pos = 0;
        while(k && pos < n){
            a[pos] = 0;
            pos++;
            k--;
        }
    }

    ll ans = 0;
    for(auto c : a) ans += c;
    cout << ans << endl; 
    
    return 0;
}