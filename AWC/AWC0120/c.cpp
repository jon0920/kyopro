#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    bool ok = true;
    auto dfs = [&](auto dfs, int x) -> void {
        ll sum = 0;
        for(int nx : G[x]){
            dfs(dfs, nx);
            sum += v[nx];
        }
        if(sum > v[x]) ok = false;
    };

    dfs(dfs, 0);

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}