#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> neg, pos;
    rep(i,n){
        ll x;
        cin >> x;
        if(x > 0) pos.push_back(x);
        else neg.push_back(-x);
    }
    sort(neg.rbegin(), neg.rend());
    sort(pos.rbegin(), pos.rend());

    vector<ll> neg_max, pos_max;
    for(int i = 0; i < neg.size(); i += k){
        neg_max.push_back(neg[i]);
    }
    for(int i = 0; i < pos.size(); i += k){
        pos_max.push_back(pos[i]);
    }

    ll ans = 0;
    for(auto x : neg_max) ans += x * 2;
    for(auto x : pos_max) ans += x * 2;

    cout << ans << endl;
    
    return 0;
}