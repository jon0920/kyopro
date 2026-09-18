#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

ll n, x;
vector<vector<ll>> a;
ll ans = 0;

void dfs(int depth, ll prod){
    if(depth == n){
        if(prod == x) ans++;
        return;
    }
    for(auto c : a[depth]){
        if(prod > x / c) continue;
        dfs(depth + 1, prod * c);
    }
}

int main(){
    
    cin >> n >> x;
    a.resize(n);
    rep(i,n){
        ll l;
        cin >> l;
        a[i].resize(l);
        rep(j,l) cin >> a[i][j];
    }

    dfs(0,1);

    cout << ans << endl;
    
    return 0;
}