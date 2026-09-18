#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> color(n, -1);
    vector<ll> a, b;
    bool ok = true;
    rep(i,n){
        if(color[i] == -1){
            color[i] = 0;
            int cnt0 = 1, cnt1 = 0;
            queue<int> que;
            que.push(i);
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(int nv : G[v]){
                    if(color[nv] == -1){
                        color[nv] = color[v] ^ 1;
                        if(color[nv] == 1) cnt1++;
                        else cnt0++;
                        que.push(nv);
                    } else if(color[nv] == color[v]){
                        ok = false;
                    }
                }
            }
            a.push_back(cnt0);
            b.push_back(cnt1);
        }
    }

    if(!ok){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i,a.size()){
        ans += (ll)a[i] * b[i];
    }
    ans -= m;

    ll sum = 0, sum2 = 0;
    rep(i,a.size()){
        ll s = a[i] + b[i];
        sum += s;
        sum2 += s * s;
    }
    ll cross = (sum * sum - sum2) / 2;
    ans += cross;
    cout << ans << endl;

    return 0;
}