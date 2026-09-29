#include <bits/stdc++.h>
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

    int q;
    cin >> q;
    while(q--){
        int x, k;
        cin >> x >> k;
        x--;
        queue<pair<int,int>> que;
        que.push({x, k});
        set<int> st;
        st.insert(x);

        while(!que.empty()){
            auto [v, rem] = que.front(); que.pop();
            if(rem == 0) continue;
            for(int nv : G[v]){
                if(!st.count(nv)){
                    st.insert(nv);
                    que.push({nv, rem - 1});
                }
            }
        }

        int res = 0;
        for(int x : st) res += x + 1;
        cout << res << endl;
    }
    
    return 0;
}