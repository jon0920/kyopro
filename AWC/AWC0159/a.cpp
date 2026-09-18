#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> s(n, vector<char>(m, '#'));
    rep(i,k){
        int r, c;
        cin >> r >> c;
        s[r - 1][c - 1] = '.';
    }

    rep(i,n){
        rep(j,m) cout << s[i][j];
        cout << endl;
    }
    
    return 0;
}