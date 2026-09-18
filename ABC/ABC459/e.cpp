#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> deg(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        deg[p[i]]++;
    }

    vector<ll> c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    vector<ll> d(n + 1);
    for(int i = 1; i <= n; i++) cin >> d[i];

    int max_d = 1000000;
    vector<mint> invfact(max_d + 1);
    invfact[0] = 1;
    mint fact = 1;
    for(int i = 1; i <= max_d; i++) fact *= i;

    invfact[max_d] = fact.inv();
    for(int i = max_d - 1; i >= 1; i--) invfact[i] = invfact[i + 1] * (i + 1);

    vector<ll> r(n + 1);
    for(int i = 1; i <= n; i++) r[i] = c[i];

    queue<int> que;
    for(int i = 1; i <= n; i++) if(deg[i] == 0) que.push(i);

    mint ans = 1;
    while(!que.empty()){
        int v = que.front(); que.pop();
        if(r[v] < d[v]){
            cout << 0 << endl;
            return 0;
        }
        
        mint ways = 1;
        rep(i,d[v]){
            ways *= mint(r[v] - i);
        }
        ways *= invfact[d[v]];

        ans *= ways;

        if(v != 1){
            r[p[v]] += r[v] - d[v];
            deg[p[v]]--;
            if(deg[p[v]] == 0) que.push(p[v]);
        }

    }
    cout << ans.val() << endl;
    
    return 0;
}