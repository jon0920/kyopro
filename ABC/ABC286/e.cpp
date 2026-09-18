#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
using TP = tuple<ll,ll,ll>;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<vector<ll>> val(n, vector<ll>(n, -INF));
    rep(i,n){
        rep(j,n){
            if(s[i][j] == 'Y'){
                dist[i][j] = 1;
                val[i][j] = a[i] + a[j];
            }
        }
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                ll d = dist[i][k] + dist[k][j];
                ll v = val[i][k] + val[k][j] - a[k];
                if(d < dist[i][j]){
                    dist[i][j] = d;
                    val[i][j] = v;
                } else if(d == dist[i][j]){
                    val[i][j] = max(val[i][j], v);
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(dist[u][v] == INF){
            cout << "Impossible" << endl;
        } else {
            cout << dist[u][v] << " " << val[u][v] << endl;
        }
    }
    
    return 0;
}