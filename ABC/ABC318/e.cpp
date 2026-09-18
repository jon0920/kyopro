#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a].push_back(i);
    }

    ll ans = 0;
    for(auto [k, v] : mp){
        int sz = v.size();
        if(sz < 2) continue;

        ll sum = 0;
        rep(i,sz){
            ll crr = v[i] - i;
            ans += crr * i - sum;
            sum += crr;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}