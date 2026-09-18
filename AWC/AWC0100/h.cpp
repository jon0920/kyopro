#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<int,int>;

int main(){
    
    int n, m;
    cin >> n >> m;
    priority_queue<P> pq;
    vector<int> b(n);
    rep(i,n){
        cin >> b[i];
        pq.push({b[i], i});
    }
    vector<vector<P>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back({v, b[v]});
    }
    rep(i,n){
        sort(G[i].begin(), G[i].end(), [](const auto &x, const auto &y){
            return x.second > y.second;
        });
    }


    vector<bool> seen(n);
    vector<int> ans;
    int st = 0;
    while(st != -1){
        int crr = st;
        while(crr != -1){
            seen[crr] = true;
            ans.push_back(crr + 1);
            int nxt = -1;
            for(auto [nv, nb] : G[crr]){
                if(!seen[nv]){
                    nxt = nv;
                    break;
                }
            }
            crr = nxt;
        }
        st = -1;
        while(!pq.empty()){
            auto [_, id] = pq.top(); pq.pop();
            if(!seen[id]){
                st = id;
                break;
            }
        }
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}