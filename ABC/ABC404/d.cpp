#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int n, m;
vector<ll> c, v;
vector<vector<int>> zoo;
ll ans = 1e18;

void dfs(int x){
    if(x == n){
        ll sum = 0;
        vector<int> seen(m, 0);
        rep(i,n){
            for(auto an : zoo[i]){
                seen[an] += v[i];
            }
        }
        bool ok = true;
        for(auto an : seen) if(an < 2) ok = false;
        rep(i,n){
            sum += c[i] * v[i];
        }
        if(ok) ans = min(ans, sum);
        return;
    }
    else{
        for(int i = 0; i <= 2; i++){
            v[x] = i;
            dfs(x + 1);
        }
    }
}

int main() {
    
    cin >> n >> m;
    c.resize(n);
    rep(i,n) cin >> c[i];
    zoo.resize(n);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            a--;
            zoo[a].push_back(i);
        }
    }
    v.resize(n);
    dfs(0);
    cout << ans << endl;
    
    return 0;
}