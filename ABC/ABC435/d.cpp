#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int x, y;
        cin >> x >> y; x--, y--;
        g[y].push_back(x);
    }

    queue<int> que;
    vector<bool> color(n, false);
    int q;
    cin >> q;
    while(q--){
        int type, v;
        cin >> type >> v;
        v--;
        if(type == 1){
            if(color[v]) continue;
            color[v] = true;
            que.push(v);
            while(!que.empty()){
                int x = que.front(); que.pop();
                for(auto a : g[x]){
                    if(color[a]) continue;
                    color[a] = true;
                    que.push(a);
                }
            }
        }
        else{
            if(color[v]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}