#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> xy(n);
    rep(i,n) cin >> xy[i].first >> xy[i].second;

    vector<vector<int>> G(n);
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            auto [ax, ay] = xy[i];
            auto [bx, by] = xy[j];
            int dist = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
            if(dist <= d * d){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    vector<bool> infection(n);

    auto dfs = [&](auto dfs, int v) -> void {
        infection[v] = true;
        for(auto nv : G[v]){
            if(!infection[nv]) dfs(dfs, nv);
        }
    };

    dfs(dfs, 0);

    for(auto i : infection) cout << (i ? "Yes" : "No") << endl;
    
    return 0;
}