#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<vector<bool>> neighbor(n, vector<bool>(n));
    rep(i,n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        neighbor[u][v] = true;
        neighbor[v][u] = true;
    }

    vector<int> color(n, -1);
    color[0] = 0;
    queue<int> que;
    que.push(0);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            if(color[nv] != -1) continue;
            color[nv] = color[v] ^ 1;
            que.push(nv);
        }
    }

    set<pair<int,int>> st;
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            if(color[i] != color[j] && !neighbor[i][j]) st.insert({i, j});
        }
    }

    if(st.size() % 2 == 1){
        cout << "First" << endl;
        auto [u, v] = *st.begin();
        st.erase({u, v});
        cout << u + 1 << " " << v + 1 << endl;
    } else {
        cout << "Second" << endl;
    }

    while(1){
        int x, y;
        cin >> x >> y;
        if(x == -1 && y == -1){
            return 0;
        } else {
            x--, y--;
            if(x > y) swap(x, y);
            st.erase({x, y});
            auto [u, v] = *st.begin();
            st.erase({u, v});
            cout << u + 1 << " " << v + 1 << endl;
        }
    }
    
    return 0;
}