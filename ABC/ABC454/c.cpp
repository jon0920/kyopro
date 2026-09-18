#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }

    vector<bool> seen(n);
    seen[0] = true;
    queue<int> que;
    que.push(0);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(seen[nv]) continue;
            
            seen[nv] = true;
            que.push(nv);
        }
    }

    int ans = 0;
    for(auto v : seen) if(v) ans++;
    cout << ans << endl;

    return 0;
}