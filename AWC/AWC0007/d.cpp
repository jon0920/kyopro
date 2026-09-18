#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> imos1(n + 1, vector<int>(n + 1)), imos2(n + 1, vector<int>(n + 1));
    rep(i,a){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--;
        imos1[r1][c1]++; imos1[r1][c2]--;
        imos1[r2][c1]--; imos1[r2][c2]++;
    }

    rep(i,b){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--;
        imos2[r1][c1]++; imos2[r1][c2]--;
        imos2[r2][c1]--; imos2[r2][c2]++;
    }

    rep(i,n){
        for(int j = 1; j < n; j++){
            imos1[i][j] += imos1[i][j - 1];
            imos2[i][j] += imos2[i][j - 1];
        }
    }

    for(int i = 1; i < n; i++){
        rep(j,n){
            imos1[i][j] += imos1[i - 1][j];
            imos2[i][j] += imos2[i - 1][j];
        }
    }

    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(imos1[i][j] > 0 && imos2[i][j] > 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}