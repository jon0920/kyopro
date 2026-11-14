#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> cnt(n + 1);
    ll ans = 1;
    
    int l = 0, r = 0;
    while(l < n){
        r = l + 1;
        while(r < n && a[l] == a[r]) r++;

        ans += l - cnt[a[l]];
        cnt[a[l]] += r - l;

        l = r;
    }

    cout << ans << endl;
    
    return 0;
}