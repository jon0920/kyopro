#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, l;
    cin >> n >> l;
    map<int,ll> mp;
    int pos = 0;
    mp[pos]++;
    rep(i,n - 1){
        int d;
        cin >> d;
        pos += d;
        pos %= l;
        mp[pos]++;
    }

    if(l % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i,(l / 3)){
        ans += mp[i] * mp[i + l / 3] * mp[i + l * 2 / 3];
    }
    cout << ans << endl;
    
    return 0;
}