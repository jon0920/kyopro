#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    priority_queue<pair<int,int>> pq;
    rep(i,n){
        int r;
        cin >> r;
        pq.push({r, i});
    }

    vector<set<int>> e(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].insert(v);
        e[v].insert(u);
    }

    vector<bool> cand(n);
    int ans;
    while(!pq.empty()){
        auto [c, i] = pq.top(); pq.pop();
        if(cand[i]) continue;

        int j;
        while(true){
            j = *e[i].begin();
            if(cand[j]) e[i].erase(j);
            else break;
        }
        if(i == 0 || j == 0){
            if(i == 0) ans = j + 1;
            else ans = i + 1;
            break;
        }
        cand[i] = true;
        cand[j] = true;
    }

    cout << ans << endl;
    return 0;
}