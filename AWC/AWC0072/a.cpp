#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s, t;
    cin >> n >> s >> t;
    string res = "";
    bool ok = true;
    rep(i,n){
        if(s[i] == t[i]) res += s[i];
        else if(s[i] == '?') res += t[i];
        else if(t[i] == '?') res += s[i];
        else{
            res += '!';
            ok = false;
        }
    }

    cout << res << endl;
    cout << (ok ? "No" : "Yes") << endl;
    
    return 0;
}