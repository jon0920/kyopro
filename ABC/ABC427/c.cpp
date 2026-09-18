#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> e;
    rep(i,m){
        int u, v;
        cin >> u >> v; u--, v--;
        e.push_back({u, v});
    }

    int ans = 100;
    for(int bit = 0; bit < (1 << n); bit++){
        int cnt = 0;
        for(auto [a,b] : e){
            if(((bit >> a) & 1) == ((bit >> b) & 1)) cnt++;
        }
        ans = min(ans, cnt);
    }
    
    cout << ans << endl;
    return 0;
}