#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    map<int,vector<int>> mp;
    rep(i,n){
        int c;
        cin >> c;
        mp[c].push_back(i);
    }

    vector<char> ans(n);
    for(auto [k, v] : mp){
        int sz = v.size();
        rep(i,sz){
            char si = s[v[i]];
            ans[v[(i + 1) % sz]] = si;
        }
    }

    for(auto c : ans) cout << c;
    cout << endl;
    
    return 0;
}