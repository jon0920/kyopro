#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    unordered_map<char,int> mp;
    for(auto c : s) mp[c]++;
    
    rep(i,s.size()){
        if(mp[s[i]] == 1){
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}