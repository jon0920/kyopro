#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> rc(m);
    rep(i,m) cin >> rc[i].first >> rc[i].second;
    reverse(rc.begin(), rc.end());

    vector<bool> used_r(n), used_c(n);
    int ans = 0;
    for(auto [r, c] : rc){
        r--, c--;
        if(!used_r[r] && !used_c[c]){
            ans++;
        }
        used_r[r] = true;
        used_c[c] = true;
    }

    cout << ans << endl;
    
    return 0;
}