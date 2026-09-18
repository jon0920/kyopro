#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = w;
    }

    rep(i,n) dist[i][i] = 0;

    rep(k,n){
        rep(i,n){
            rep(j,n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<int> ans(n);
    rep(k,n){
        rep(i,n){
            if(k == i) continue;
            rep(j,n){
                if(j == i || j == k) continue;
                if(dist[i][j] == dist[i][k] + dist[k][j]){
                    ans[k]++;
                }
            }
        }
    }

    for(int x : ans) cout << x << endl;
    
    return 0;
}