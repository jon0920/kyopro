#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    map<string,int> mp;
    rep(i,n-k+1){
        string t = s.substr(i,k);
        mp[t]++;
    }
    int mx = 0;
    for(auto [key, val] : mp) mx = max(mx, val);

    vector<string> ans;
    for(auto [key, val] : mp) if(val == mx) ans.push_back(key);
    sort(ans.begin(), ans.end());

    cout << mx << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}