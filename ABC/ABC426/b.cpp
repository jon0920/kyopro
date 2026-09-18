#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto c : s) mp[c]++;
    for(auto [k, v] : mp){
        if(v == 1) cout << k << endl;
    }
    
    return 0;
}