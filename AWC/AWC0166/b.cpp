#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    map<ll,ll> mp;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    rep(i,m){
        ll g;
        cin >> g;
        mp[g] += k;
    }

    int ans = 0;
    for(ll x : s){
        auto it = mp.upper_bound(x);
        if(it == mp.begin()) continue;
        it--;
        if(it->second == 0){
            continue;
        }
        it->second--;
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}