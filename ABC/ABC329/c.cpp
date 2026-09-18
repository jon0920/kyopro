#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char,int> mp;
    int i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n && s[i] == s[j]) j++;
        mp[s[i]] = max(mp[s[i]], j - i);
        i = j;
    }
    int ans = 0;
    for(auto [k, v] : mp){
        ans += v;
    }
    cout << ans << endl;
    
    return 0;
}