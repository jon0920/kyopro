#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    vector<int> a(n), w(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> w[i];
    rep(i,n) mp[a[i]].push_back(w[i]);

    ll ans = 0;
    for(auto [k, v] : mp){
        if(v.size() >= 2){
            sort(v.begin(), v.end());
            rep(i,v.size() - 1) ans += v[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}