#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, q;
    cin >> n >> q;
    ll ans = 0;
    vector<ll> row_update(n), col_update(n);
    fenwick_tree<ll> fw_black(q + 1), fw_white(q + 1);
    fw_white.add(0,n);
    
    for(ll qi = 1; qi <= q; qi++){
        int type;
        cin >> type;
        if(type == 1){
            int r;
            cin >> r; r--;
            int prev = row_update[r];

            ans += fw_white.sum(prev,qi);

            if(prev > 0) fw_black.add(prev, -1);
            
            fw_black.add(qi,1);
            row_update[r] = qi;
        } else {
            int c;
            cin >> c; c--;
            int prev = col_update[c];

            ll dec = fw_black.sum(prev, qi);
            ans -= dec;

            fw_white.add(prev,-1);
            fw_white.add(qi,1);
            col_update[c] = qi;
        }

        cout << ans << endl;
    }

    return 0;
}