#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<ll,ll>> rt(n);
    rep(i,n){
        ll t, r;
        cin >> t >> r;
        rt[i] = {r, t};
    }
    sort(rt.begin(), rt.end());

    ll ans = 0;
    rep(i,n){
        if(i != n - 1){
            ans += rt[i].first + rt[i].second;
        } else {
            ans += rt[i].second;
        }
    }

    cout << ans << endl;
    
    return 0;
}