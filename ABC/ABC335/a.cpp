#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n){
        if(i != n - 1) cout << s[i];
        else cout << 4 << endl;
    }
    
    
    return 0;
}