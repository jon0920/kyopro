#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    string s;
    cin >> n >> s >> q;
    
    string to, from;
    to = from = "abcdefghijklmnopqrstuvwxyz";
    rep(i,q){
        char c, d;
        cin >> c >> d;
        for(auto &x : to) if(x == c) x = d;
    }
    for(auto c : s){
        rep(i,26){
            if(c == from[i]) cout << to[i];
        }
    }
    cout << endl;
    
    return 0;
}