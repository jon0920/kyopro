#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<vector<ll>> G(n);
    rep(i,n) cin >> v[i];
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }

    vector<ll> sum(n);
    sum[0] = v[0];
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        for(auto nxt : G[now]){
            sum[nxt] = sum[now] + v[nxt];
            que.push(nxt);
        }
    }

    while(q--){
        int x;
        cin >> x;
        x--;
        cout << sum[x] << endl;
    }

    return 0;
}