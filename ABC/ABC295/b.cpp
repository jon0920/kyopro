#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int r, c;
    cin >> r >> c;
    vector<vector<char>> b(r, vector<char>(c));
    rep(i,r) rep(j,c) cin >> b[i][j];

    vector<vector<bool>> check(r, vector<bool>(c));
    rep(i,r){
        rep(j,c){
            int p = b[i][j] - '0';
            if(p >= 1 && p <= 9){
                for(int x = i - p; x <= i + p; x++){
                    for(int y = j - p; y <= j + p; y++){
                        if(x < 0 || x >= r || y < 0 || y >= c) continue;
                        if(abs(x - i) + abs(y - j) > p) continue;
                        check[x][y] = true;
                    }
                }
            }
        }
    }

    rep(i,r){
        rep(j,c){
            if(check[i][j]) cout << '.';
            else cout << b[i][j];
        }
        cout << endl;
    }

    return 0;
}