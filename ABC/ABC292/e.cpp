#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<set<int>> st(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        st[u].insert(v);
    }
    
    ll sum = 0;
    rep(i,n){
        vector<bool> seen(n, false);
        queue<int> que;
        seen[i] = true;
        que.push(i);

        int cnt = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto nv : G[v]){
                if(!seen[nv]){
                    seen[nv] = true;
                    cnt++;
                    que.push(nv);
                }
            }
        }
        sum += cnt;
    }

    cout << sum - m << endl;
    
    return 0;
}