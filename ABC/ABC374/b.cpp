#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;
    
    int n = min(s.size(), t.size());
    rep(i,n){
        if(s[i] != t[i]){
            cout << i + 1 << endl;
            return 0;
        }
    }

    if(s.size() != t.size()){
        cout << n + 1 << endl;
        return 0;
    } else {
        cout << 0 << endl;
    }

    return 0;
}