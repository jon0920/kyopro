#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int h, w; ll c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];

    vector<vector<ll>> mn1(h, vector<ll>(w, INF));
    ll ans = INF;
    rep(i,h){
        rep(j,w){
            ll best = INF;
            if(i > 0) best = min(best, mn1[i - 1][j]);
            if(j > 0) best = min(best, mn1[i][j - 1]);

            if(best != INF){
                ans = min(ans, best + a[i][j] + c * i + c * j);
            }

            mn1[i][j] = min(best, a[i][j] - c * i - c * j);
        }
    }

    vector<vector<ll>> mn2(h, vector<ll>(w, INF));
    rep(i,h){
        for(int j = w - 1; j >= 0; j--){
            ll best = INF;
            if(i > 0) best = min(best, mn2[i - 1][j]);
            if(j < w - 1) best = min(best, mn2[i][j + 1]);

            if(best != INF){
                ans = min(ans, best + a[i][j] + c * i + c * (w - j - 1));
            }

            mn2[i][j] = min(best, a[i][j] - c * i - c * (w - j - 1));
        }
    }

    cout << ans << endl;
    
    return 0;
}