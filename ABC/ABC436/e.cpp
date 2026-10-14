#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i,n){
        int p;
        cin >> p;
        p--;
        G[i].push_back(p);
    }

    vector<bool> seen(n);
    ll ans = 0;
    rep(i,n){
        if(!seen[i]){
            seen[i] = true;
            queue<int> que;
            que.push(i);
            ll cnt = 1;
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(int nv : G[v]){
                    if(!seen[nv]){
                        cnt++;
                        seen[nv] = true;
                        que.push(nv);
                    }
                }
            }
            ans += cnt * (cnt - 1) / 2;
        }
    }

    cout << ans << endl;
    
    return 0;
}