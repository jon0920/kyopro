#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<ll>> dist(h, vector<ll>(w));
    rep(i,h) rep(j,w){
        if(s[i][j] == 'x') dist[i][j] = INF;
        else if(s[i][j] == '.') dist[i][j] = 1;
        else dist[i][j] = 0;
    }
    
    vector<vector<ll>> sum_r(h, vector<ll>(w + 1)), sum_c(w, vector<ll>(h + 1));
    rep(i,h){
        rep(j,w){
            sum_r[i][j + 1] = sum_r[i][j] + dist[i][j];
        }
    }
    rep(i,w){
        rep(j,h){
            sum_c[i][j + 1] = sum_c[i][j] + dist[j][i];
        }
    }

    ll ans = INF;
    rep(i,h){
        rep(j,w - k + 1) ans = min(ans, sum_r[i][j + k] - sum_r[i][j]);
    }
    rep(i,w){
        rep(j,h - k + 1) ans = min(ans, sum_c[i][j + k] - sum_c[i][j]);
    }

    if(ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}