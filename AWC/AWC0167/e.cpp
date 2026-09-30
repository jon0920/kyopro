#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 1e9;
    rep(i,m){
        int u, v, w;
        cin >> u >> v >> w;
        ans = min(ans, w);
    }

    cout << ans << endl;
    
    return 0;
}