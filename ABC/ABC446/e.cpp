#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int m, a, b;
    cin >> m >> a >> b;
    vector<vector<int>> e(m * m);
    for(int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            int z = (a * y + b * x) % m;
            e[y * m + z].push_back(x * m + y);
        }
    }

    vector<bool> seen(m * m);
    queue<int> que;
    rep(x,m) rep(y,m){
        if(x == 0 || y == 0){
            int v = x * m + y;
            seen[v] = true;
            que.push(v);
        }
    }

    while(!que.empty()){
        int v = que.front(); que.pop();

        for(auto nv : e[v]){
            if(!seen[nv]){
                seen[nv] = true;
                que.push(nv);
            }
        }
    }

    int ans = 0;
    rep(x,m) rep(y,m){
        if(!seen[x * m + y]) ans++;
    }

    cout << ans << endl;

    return 0;
}