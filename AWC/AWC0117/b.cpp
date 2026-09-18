#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];

    int cur = 0;
    vector<ll> vol(n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll v;
            cin >> v;
            for(int i = cur; i < n; i++){
                if(c[i] - vol[i] >= v){
                    vol[i] += v;
                    break;
                } else {
                    v -= c[i] - vol[i];
                    vol[i] = c[i];
                    cur++;
                }
            }
        } else {
            int k;
            cin >> k;
            k--;
            cout << vol[k] << endl;
        }
    }
    
    return 0;
}