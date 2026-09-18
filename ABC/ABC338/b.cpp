#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto c : s) mp[c]++;
    int mx = 0;
    for(auto [k,v] : mp){
        mx = max(mx, v);
    }
    for(auto [k,v] : mp){
        if(v == mx){
            cout << k << endl;
            return 0;
        }
    }
    
    return 0;
}