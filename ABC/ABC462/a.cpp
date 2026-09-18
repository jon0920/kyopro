#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;

    rep(i,s.size()){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) cout << s[i];
    }
    cout << endl;
    
    return 0;
}