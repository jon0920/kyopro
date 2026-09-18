#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n);
    rep(i,n - 1){
        int p;
        cin >> p;
        p--;
        G[p].push_back(i + 1);
    }

    vector<ll> diff(n);
    rep(i,q){
        int x; ll d;
        cin >> x >> d;
        x--;
        diff[x] += d;
    }

    vector<ll> res(n);
    ll crr = 0;
    auto dfs = [&](auto dfs, int x) -> void {
        crr += diff[x];
        res[x] += crr;
        for(auto nx : G[x]){
            dfs(dfs, nx);
        }
        crr -= diff[x];
    };

    dfs(dfs, 0);

    for(auto x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}