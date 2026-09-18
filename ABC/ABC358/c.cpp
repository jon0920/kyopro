#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int ans = 100;
    int cnt = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<bool> check(m, false);
        bool ok = true;
        cnt = 0;
        rep(i,n){
            if(bit & (1 << i)){
                cnt++;
                rep(j,m){
                    if(s[i][j] == 'o') check[j] = true;
                }
            }
        }
        rep(k,m){
            if(!check[k]){
                ok = false;
                break;
            }
        }
        if(ok) ans = min(ans, cnt);
    }
    cout << ans << endl;

    
    return 0;
}