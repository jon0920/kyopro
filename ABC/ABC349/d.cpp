#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll l, r;
    cin >> l >> r;

    vector<pair<ll,ll>> ans;
    ll crr = l;
    while(crr != r){
        ll d = r - crr;
        ll x1 = 1;
        while(x1 * 2 <= d){
            x1 *= 2;
        }
        ll x2 = crr & -crr;
        ll x;
        if(x2 == 0) x = x1;
        else x = min(x1, x2);
        ans.push_back({crr, crr + x});
        crr += x;
    }

    cout << ans.size() << endl;
    for(auto [x, y] : ans){
        cout << x << " " << y << endl;
    }
    
    return 0;
}