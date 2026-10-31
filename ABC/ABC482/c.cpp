#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w, n, q;
    cin >> h >> w >> n >> q;
    vector<int> row(n), col(n);
    rep(i,n){
        cin >> row[i] >> col[i];
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, d;
            cin >> u >> d;
            int ans = upper_bound(row.begin(), row.end(), d) - lower_bound(row.begin(), row.end(), u);
            cout << ans << endl;
        } else {
            int l, r;
            cin >> l >> r;
            int ans = upper_bound(col.begin(), col.end(), r) - lower_bound(col.begin(), col.end(), l);
            cout << ans << endl;
        }
    }
    
    return 0;
}