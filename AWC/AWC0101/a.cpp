#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> sum(n);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        sum[u] += w;
        sum[v] += w;
    }

    int ans = 0;
    rep(i,n) if(sum[i] < s[i]) ans++;
    cout << ans << endl;
    
    return 0;
}