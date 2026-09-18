#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int h, w, k;
    cin >> h >> w >> k;
    char c1, c2;
    cin >> c1 >> c2;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<char>> res(h * k, vector<char>(w * k));
    rep(i,h) rep(j,w){
        rep(ki,k){
            rep(kj,k){
                res[i * k + ki][j * k + kj] = s[i][j];
            }
        }
    }

    rep(i,h*k){
        rep(j,w*k){
            if(res[i][j] == '#') cout << c1;
            else cout << c2;
        }
        cout << endl;
    }


    return 0;
}