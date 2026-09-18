#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,n - 1){
        int p;
        cin >> p;
        p--;
        G[p].push_back(i + 1);
    }

    vector<int> cnt(n, -1);
    rep(i,m){
        int x, y;
        cin >> x >> y;
        x--;
        cnt[x] = max(cnt[x], y);
    }

    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            cnt[nv] = max(cnt[nv], cnt[v] - 1);
            que.push({nv});
        }
    }

    int ans = 0;
    rep(i,n) if(cnt[i] >= 0) ans++;
    cout << ans << endl;
    
    return 0;
}