#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    rep(i,h){
        string s;
        cin >> s;
        bool ok = false;
        rep(j,w){
            if(s[j] == 'o'){
                cout << j + 1 << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
    
    return 0;
}