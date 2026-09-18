#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    rep(i,26){
        bool flag = false;
        rep(j,s.size()){
            if(s[j] == 'a' + i) flag = true;
        }
        if(!flag){
            cout <<  char('a' + i) << endl;
            return 0;
        }
        }
    
    return 0;
}