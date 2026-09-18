#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;

    int pos = 0;
    rep(i,3){
        char c = tolower(t[i]);
        if(i == 2 && c == 'x') break;
        while(c != s[pos]){
            pos++;
            if(pos >= s.size()){
                cout << "No" << endl;
                return 0;
            }
        }
        pos++;
    }
    cout << "Yes" << endl;
    
    return 0;
}