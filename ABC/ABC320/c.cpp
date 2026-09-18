#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int m;
    cin >> m;
    vector<string> s(3);
    rep(i,3) cin >> s[i];

    int ans = 1e9;
    rep(i,m*3) rep(j,m*3) rep(k,m*3){
        if(i == j || i == k || j == k) continue;
        if(s[0][i % m] == s[1][j % m] && s[1][j % m] == s[2][k % m]){
            ans = min(ans, max({i,j,k}));
        } 
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    
    return 0;
}