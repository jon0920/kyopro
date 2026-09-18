#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];

    vector<vector<ll>> sum(n, vector<ll>(m + 1));
    rep(i,n){
        rep(j,m) sum[i][j + 1] = sum[i][j] + a[i][j];
    }

    ll ans = -1e9;
    for(int y1 = 0; y1 < m; y1++){
        for(int y2 = y1 + 1; y2 <= m; y2++){
            ll crr = 0, sum_min = 0;
            rep(i,n){
                crr += sum[i][y2] - sum[i][y1];
                ans = max(ans, crr - sum_min);
                sum_min = min(sum_min, crr);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}