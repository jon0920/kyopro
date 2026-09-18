#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector a(n, vector(n, vector(n, 0)));
    rep(i,n) rep(j,n) rep(k,n) cin >> a[i][j][k];

    vector sum(n + 1, vector(n + 1, vector(n + 1, 0)));
    rep(i,n) rep(j,n) rep(k,n){
        sum[i+1][j+1][k+1] =
            sum[i][j+1][k+1] + sum[i+1][j][k+1] + sum[i+1][j+1][k]
            - sum[i][j][k+1] - sum[i][j+1][k] - sum[i+1][j][k]
            + sum[i][j][k] + a[i][j][k];
    }

    int q;
    cin >> q;
    while(q--){
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; ly--; lz--;
        cout << sum[rx][ry][rz] - sum[lx][ry][rz] - sum[rx][ly][rz] - sum[rx][ry][lz]
                + sum[lx][ly][rz] + sum[lx][ry][lz] + sum[rx][ly][lz] - sum[lx][ly][lz] << endl;
    }
    
    return 0;
}