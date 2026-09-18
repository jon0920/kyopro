#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    unordered_map<int,vector<int>> mp;
    rep(i,n){
        int a, c;
        cin >> a >> c;
        mp[c].push_back(a);
    }
    int ans = 0;
    for(auto [a, b] : mp){
        int mn = 1e9;
        for(auto x : b) mn = min(x, mn);
        ans = max(mn, ans);
    }
    cout << ans << endl;
    
    return 0;
}