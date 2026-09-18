#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> b(n, vector<ll>(m));
    rep(i,n) rep(j,m) cin >> b[i][j];
    vector<vector<int>> imos(n + 1, vector<int>(m + 1));
    while(q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--;
        imos[r1][c1]++;
        imos[r1][c2]--;
        imos[r2][c1]--;
        imos[r2][c2]++;
    }

    rep(i,n){
        for(int j = 1; j < m; j++) imos[i][j] += imos[i][j - 1];
    }
    rep(j,m){
        for(int i = 1; i < n; i++) imos[i][j] += imos[i - 1][j];
    }

    ll ans = 0;
    rep(i,n) rep(j,m){
        if(imos[i][j] % 2 == 0) ans += b[i][j];
        else ans += b[i][j] * 2;
    }

    cout << ans << endl;
    
    return 0;
}