#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    rep(i,m){
        int c;
        cin >> c;
        a[i].resize(c);
        rep(j,c) cin >> a[i][j];
    }

    int ans = 0;
    for(int bit = 1; bit < (1 << m); bit++){
        vector<bool> exist(n + 1, false);
        rep(i,m){
            if((bit >> i) & 1){
                for(auto c : a[i]) exist[c] = true;
            }
        }
        bool ok = true;
        for(int b = 1; b <= n; b++) if(!exist[b]) ok = false;
        if(ok) ans++;
    }
    cout << ans << endl;
    
    return 0;
}