#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    set<pair<int,int>> st;
    rep(i,m){
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        u--, v--;
        if(st.count({u, v})) continue;
        st.insert({u, v});
        G[u].push_back(v);
    }

    set<int> rem = {0};
    queue<int> que;
    vector<bool> seen(n);
    seen[0] = true;
    int res = 0;
    for(int k = 0; k < n; k++){
        if(!rem.empty() && *rem.begin() == k){
            rem.erase(k);
            que.push(k);
        }

        while(!que.empty()){
            int v = que.front(); que.pop();
            res++;
            for(int nv : G[v]){
                if(!seen[nv]){
                    seen[nv] = true;
                    if(nv > k) rem.insert(nv);
                    else {
                        que.push(nv);
                    }
                }
            }
        }

        if(res == k + 1) cout << rem.size() << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}