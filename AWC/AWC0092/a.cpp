#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> s(n), c(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> c[i];

    vector<bool> check(n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            for(int i = l; i < r; i++){
                if(!check[i]) c[i] += v;
            }
        } else if(type == 2){
            int x;
            cin >> x;
            check[x - 1] = true;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            ll ans = 0;
            for(int i = l; i < r; i++){
                if(!check[i] && c[i] <= 0) ans += s[i];
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}