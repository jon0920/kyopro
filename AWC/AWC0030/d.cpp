#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> t(n);
    rep(i,n){
        cin >> t[i];
        t[i]--;
    }

    vector<int> stats(n, 0), ans(n, 0);

    auto dfs = [&](auto self ,int v) -> void {
        stats[v] = 1;
        int to = t[v];

        if(stats[to] == 0) self(self, to);
        else if(stats[to] == 1){
            int cur = to;
            int sz = 1;
            while(t[cur] != to){
                cur = t[cur];
                sz++;
            }
            cur = to;
            do{
                ans[cur] = sz;
                cur = t[cur];
            }while(cur != to);
            
        }
        if(ans[v] == 0) ans[v] = ans[to];
        stats[v] = 2;
    };

    rep(i,n) if(stats[i] == 0) dfs(dfs, i);
    
    rep(i,n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}