#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<string> s(8);
    rep(i,8) cin >> s[i];

    vector<vector<bool>> canput(8,vector<bool>(8, true));
    rep(i,8) rep(j,8){
        if(s[i][j] == '#'){
            rep(k,8) canput[k][j] = false;
            rep(k,8) canput[i][k] = false;
        }
    }

    int ans = 0;
    rep(i,8) rep(j,8){
        if(canput[i][j]) ans++;
    }
    cout << ans << endl;
    return 0;
}