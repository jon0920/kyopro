#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n);
    rep(i,n) rep(j,n) cin >> a[i][j];

    vector<vector<ll>> sum(n + 1, vector<ll>(n + 1));
    rep(i,n) rep(j,n){
        sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
    }

    auto sum2d = [&](int xi, int yi, int xf, int yf){
        ll res = 0;
        res += sum[xf][yf];
        res -= sum[xi][yf];
        res -= sum[xf][yi];
        res += sum[xi][yi];
        return res;
    };
    
    ll ans = 0;
    rep(i,n - k + 1){
        rep(j,n - k + 1){
            ll total = sum2d(i, j, i + k, j + k);
            ll mx = 0;
            ans = max(ans, total - mx);
        }
    }

    cout << ans << endl;
    
    return 0;
}