#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = c;
    }

    ll ans = 0;
    rep(k,n){
        rep(s,n){
            rep(t,n){
                dist[s][t] = min(dist[s][t], dist[s][k] + dist[k][t]);
                if(dist[s][t] < INF) ans += dist[s][t];
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}