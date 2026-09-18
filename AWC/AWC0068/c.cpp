#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<tuple<int,int,int>> tp(m);
    rep(i,m){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        tp[i] = {u, v, c};
    }
    reverse(tp.begin(), tp.end());

    vector<int> res(n, -1);
    for(auto [x, y, c] : tp){
        if(res[x] != -1) continue;
        queue<int> que;
        que.push(x);
        res[x] = c;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto nv : G[v]){
                if(res[nv] != -1) continue;
                res[nv] = c;
                que.push(nv);
            }
        }
    }

    set<int> st;
    for(auto x : res) if(x != -1) st.insert(x);

    cout << st.size() << endl;

    return 0;
}