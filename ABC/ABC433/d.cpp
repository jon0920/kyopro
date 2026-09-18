#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<unordered_map<ll,ll>> cnt(11);
    vector<ll> len(n);
    vector<ll> ar(n);

    rep(i,n){
        len[i] = to_string(a[i]).size();
        ar[i] = a[i] % m;
        cnt[len[i]][ar[i]]++;
    }

    vector<ll> p10(11, 1);
    for(int i = 1; i <= 10; i++) p10[i] = (p10[i - 1] * 10LL) % m;

    ll ans = 0;
    rep(i,n){
        for(int j = 1; j <= 10; j++){
            ll u = (ar[i] * p10[j]) % m;
            ll v = (m - u) % m;
            ans += cnt[j][v];
        }
    }

    cout << ans << endl;
    
    return 0;
}