#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dsu uf(n);
    vector<int> ans = {0};
    int cur = 0;
    for(int i = n - 1; i >= 1; i--){
        cur++;
        for(int x : G[i]){
            if(x > i){
                if(!uf.same(i, x)){
                    cur--;
                    uf.merge(i, x);
                }
            }
        }
        ans.push_back(cur);
    }

    reverse(ans.begin(), ans.end());
    for(int x :ans){
        cout << x << endl;
    }
    
    return 0;
}