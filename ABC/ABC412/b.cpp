#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;
    bool res = true;
    for(int i = 1; i < s.size(); i++){
        if(isupper(s[i])){
            if(t.find(s[i - 1]) == string::npos) res = false;
        }
    }
    cout << (res ? "Yes" : "No") << endl;
    
    return 0;
}