#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    bool ok = true;
    rep(i,n){
        if(s[i] != t[i] && t[i] != '*') ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}