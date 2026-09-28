#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> x(n), c(n);
    rep(i,n) cin >> x[i], x[i]--;
    rep(i,n) cin >> c[i];

    dsu uf(n);
    ll ans = 0;
    rep(i,n){
        if(!uf.same(i, x[i])){
            uf.merge(i, x[i]);
            continue;
        }
        ll cost = c[i];
        int cur = x[i];
        while(cur != i){
            cost = min(cost, c[cur]);
            cur = x[cur];
        }
        ans += cost;
    }

    cout << ans << endl;
    
    return 0;
}