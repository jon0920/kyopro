#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll x, H;
            cin >> x >> H;
            h[x - 1] = H;
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            ll v = 1e9;
            int id = -1;
            for(int i = a; i <= b; i++){
                ll L = 0, R = 0;
                rep(j,a){
                    
                }
            }
        }
    }
    
    return 0;
}