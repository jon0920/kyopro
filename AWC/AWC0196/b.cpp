#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    string res;
    rep(i,h){
        string s;
        cin >> s;
        bool ok = false;
        for(char c : s){
            if(c == 'T') ok = true;
        }
        if(ok) res += 'o';
        else res += 'x';
    }

    cout << res << endl;
    
    return 0;
}