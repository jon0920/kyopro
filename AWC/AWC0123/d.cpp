#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> deg(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        deg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i,n){
        if(deg[i] == 0) pq.push(i);
    }

    vector<int> res;
    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        res.push_back(v);
        for(int nv : G[v]){
            deg[nv]--;
            if(deg[nv] == 0) pq.push(nv);
        }
    }

    if(res.size() == n){
        for(int v : res) cout << v + 1 << " ";
        cout << endl;
    } else cout << -1 << endl;
    
    return 0;
}