#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    bool res = true;
    rep(i,h){
        string s;
        cin >> s;
        bool ok = false;
        for(char c : s){
            if(c == 'o') ok = true;
        }
        if(!ok) res = false;
    }

    cout << (res ? "Yes" : "No") << endl;
    
    return 0;
}