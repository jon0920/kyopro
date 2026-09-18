#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> in_deg(n);
    set<pair<int,int>> st;
    rep(i,m){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(st.count({x, y})) continue;
        st.insert({x, y});
        in_deg[y]++;
        G[x].push_back(y);
    }

    queue<int> que;
    rep(i,n){
        if(in_deg[i] == 0) que.push(i);
    }
    if(que.empty()){
        cout << "No" << endl;
        return 0;
    }

    int num = 1;
    vector<int> ans(n);
    while(!que.empty()){
        if(que.size() != 1){
            cout << "No" << endl;
            return 0;
        }
        int v = que.front(); que.pop();
        ans[v] = num;
        num++;
        for(int nv : G[v]){
            in_deg[nv]--;
            if(in_deg[nv] == 0) que.push(nv);
        }
    }

    cout << "Yes" << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}