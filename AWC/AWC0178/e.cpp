#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;
using P = pair<ll,ll>;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> b(m, vector<int>(n));
    vector<int> c(m);
    rep(i,m){
        rep(j,n) cin >> b[i][j];
        cin >> c[i];
    }

    set<ll> st;
    rep(i,k){
        ll res = 0;
        for(int j = n - 1; j >= 0; j--){
            int f;
            cin >> f;
            if(f == 1) res |= (1LL << j);
        }
        st.insert(res);
    }

    vector<ll> dist(1LL << n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [cost, mask] = pq.top(); pq.pop();
        if(dist[mask] != cost) continue;
        rep(i,m){
            ll next_mask = mask;
            rep(j,n){
                if(b[i][j] == 1) next_mask ^= (1LL << (n - j - 1));
            }
            if(!st.count(next_mask)){
                if(dist[next_mask] > dist[mask] + c[i]){
                    dist[next_mask] = dist[mask] + c[i];
                    pq.push({dist[next_mask], next_mask});
                }
            }
        }
    }

    cout << (dist[(1<<n) - 1] == INF ? -1 : dist[(1<<n) - 1]) << endl;
    
    return 0;
}