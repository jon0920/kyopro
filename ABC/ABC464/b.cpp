#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int u = 50, d = 0, l = 50, r = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                u = min(u, i);
                d = max(d, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }

    for(int i = u; i <= d; i++){
        for(int j = l; j <= r; j++){
            cout << s[i][j];
        }
        cout << endl;
    }
    
    return 0;
}