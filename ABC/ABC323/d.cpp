#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        ll s, c;
        cin >> s >> c;

        int f = s;
        while(f % 2 == 0) f /= 2;
        mp[f] += (s / f) * c;
    }

    ll res = 0;
    for(auto [v, num] : mp) res += __builtin_popcountll(num);
    cout << res << endl;
    
    return 0;
}