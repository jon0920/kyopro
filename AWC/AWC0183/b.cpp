#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    rep(i,h){
        rep(j,w){
            if(s[i][j] == 'X'){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}