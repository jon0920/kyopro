#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    bool ok = true;
    rep(i,s.size()){
        if(s[i] == '|' && ok) ok = false;
        else if(s[i] == '|' && !ok){
            ok = true;
            continue;
        }
        if(ok) cout << s[i];
    }
    cout << endl;
    
    return 0;
}