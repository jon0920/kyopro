#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<ll>> sum(1 << n, vector<ll>(n));
    vector<vector<ll>> cnt(1 << n, vector<ll>(n));
    sum[1 << s][s] = c[s];
    cnt[1 << s][s] = 1;

    for(int ss = 0; ss < (1 << n); ss++){
        rep(v,n){
            if(cnt[ss][v] == 0) continue;
            if(v == t) continue;

            for(int nv : G[v]){
                if(!(ss & (1 << nv))){
                    int ns = ss | (1 << nv);
                    cnt[ns][nv] += cnt[ss][v];
                    sum[ns][nv] += sum[ss][v] + cnt[ss][v] * c[nv];
                }
            }
        }
    }

    ll total_cnt = 0, total_sum = 0;
    for(int ss = 0; ss < (1 << n); ss++){
        total_cnt += cnt[ss][t];
        total_sum += sum[ss][t];
    }

    cout << fixed << setprecision(17);
    cout << (double)total_sum / total_cnt << endl;

    return 0;
}