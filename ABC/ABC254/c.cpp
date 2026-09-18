#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    map<int,vector<int>> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[i % k].push_back(a);
    }

    for(auto &[key, val] : mp){
        sort(val.begin(), val.end());
    }

    vector<int> ans(n);
    for(auto [key,val] : mp){
        int m = val.size();
        rep(i,m){
            ans[key + i * k] = val[i];
        }
    }

    bool ok = true;
    rep(i,n - 1){
        if(ans[i + 1] < ans[i]) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}