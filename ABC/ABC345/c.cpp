#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    ll n = s.size();
    unordered_map<char,ll> mp;
    for(auto c : s) mp[c]++;
    ll ans = n * (n - 1) / 2;
    ll cnt = 0;
    for(auto [k,v] : mp){
        if(v >= 2) cnt = 1;
        ans -= v * (v - 1) / 2;
    }
    cout << ans + cnt << endl;
    
    return 0;
}