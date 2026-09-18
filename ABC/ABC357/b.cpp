#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int ucnt = 0, lcnt = 0;
    rep(i,s.size()){
        if(isupper(s[i])) ucnt++;
        else lcnt++;
    }
    if(ucnt > lcnt) for(char c : s) cout << (char)toupper(c);
    else for(char c : s) cout << (char)tolower(c);
    cout << endl;
    
    return 0;
}