#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<vector<int>> parent(20, vector<int>(n, -1));
    vector<int> depth(n, 0);
    vector<vector<int>> child(n);

    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        parent[0][i] = p;
        child[p].push_back(i);
    }

    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : child[v]){
            depth[nv] = depth[v] + 1;
            que.push(nv);
        }
    }

    for(int k = 0; k < 19; k++){
        for(int i = 0; i < n; i++){
            if(parent[k][i] != -1){
                parent[k + 1][i] = parent[k][parent[k][i]];
            }
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(depth[x] < depth[y]) swap(x, y);

        rep(k,20){
            if((depth[x] - depth[y]) >> k & 1) x = parent[k][x];
        }

        if(x == y){
            cout << x + 1 << endl;
            continue;
        }
        for(int k = 19; k >= 0; k--){
            if(parent[k][x] != parent[k][y]){
                x = parent[k][x];
                y = parent[k][y];
            }
        }

        cout << parent[0][x] + 1 << endl;
    }

    return 0;
}