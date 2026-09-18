#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int n, m;
vector<vector<int>> edge(11, vector<int>(11, 0));
vector<bool> visited(11, false);

int ans = 0;
void dfs(int v, int sum){
    visited[v] = true;
    ans = max(ans, sum);
    for(int i = 1; i <= n; i++){
        if(!visited[i] && edge[v][i]) dfs(i, sum + edge[v][i]);
    }
    visited[v] = false;
}

int main() {
    
    cin >> n >> m;
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
    }

    for(int i = 1; i <= n; i++) dfs(i, 0);

    cout << ans << endl;
    
    return 0;
}