#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;

    int r = m % 10;
    if(r == 0) r = 10;
    vector<int> res(n);
    vector<vector<int>> ans;

    auto dfs = [&](auto dfs, int d) -> void {
        if(d == n){
            vector<int> tmp(n);
            rep(i,n) tmp[i] = res[i];
            ans.push_back(res);
            return;
        }
        for(int i = 1; i <= r; i++){
            res[d] = i + (d * 10);
            if(d != 0){
                if(res[d] < res[d - 1] + 10) continue;
            }
            dfs(dfs, d + 1);
        }
    };

    dfs(dfs, 0);

    cout << ans.size() << endl;
    for(auto v : ans){
        for(auto x : v) cout << x << " ";
        cout << endl;
    }
    

    return 0;
}