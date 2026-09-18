#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    map<pair<int,int>,int> mp;
    int ans = 0;
    rep(i,m){
        int u, v;
        cin >> u >> v;
        if(u == v){
            ans++;
            continue;
        }
        if(u < v) swap(u,v);
        mp[{u,v}]++;
    }

    for(auto &[edge, k] : mp){
        ans += k - 1;
    }

    cout << ans << endl;
    
    return 0;
}