#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    vector<bool> ok(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(w[u] > w[v]) ok[v] = true;
        if(w[u] < w[v]) ok[u] = true;
    }

    int ans = 0;
    rep(i,n) if(ok[i]) ans++;
    cout << ans << endl;
    
    return 0;
}