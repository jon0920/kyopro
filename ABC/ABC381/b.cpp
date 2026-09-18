#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    map<char,int> freq;
    for(char c : s){
        freq[c]++;
    }
    for(auto [ch, cnt] : freq){
        if(cnt != 2){
            cout << "No" << endl;
            return 0;
        }
    }

    int n = s.size() / 2;
    rep(i,n){
        if(s[2 * (i + 1) - 2] != s[2 * (i + 1) - 1]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}