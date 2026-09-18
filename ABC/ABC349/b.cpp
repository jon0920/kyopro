#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto c : s) mp[c]++;
    map<int,int> ans;
    for(auto [k,v] : mp) ans[v]++;
    for(auto [k,v] : ans){
        if(v != 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}