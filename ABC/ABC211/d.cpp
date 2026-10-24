#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(n, -1);
    vector<mint> cnt(n);
    queue<int> que;
    dist[0] = 0;
    cnt[0] = 1;
    que.push(0);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            if(dist[nv] == -1){
                dist[nv] = dist[v] + 1;
                cnt[nv] = cnt[v];
                que.push(nv);
            } else if(dist[nv] == dist[v] + 1){
                cnt[nv] += cnt[v];
            }
        }
    }

    cout << cnt[n - 1].val() << endl;
    
    return 0;
}