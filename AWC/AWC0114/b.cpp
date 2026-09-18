#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0;
    if(k == 0){
        map<ll,int> mp;
        for(ll x : a) mp[x]++;
        for(ll x : a) if(mp[x] >= 2) ans++;
    } else {
        set<ll> st;
        for(ll x : a) st.insert(x);
        for(ll x : a){
            if(st.count(x - k) || st.count(x + k)) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}