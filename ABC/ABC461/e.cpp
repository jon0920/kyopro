#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    fenwick_tree<int> row(q + 1), col(q + 1);
    vector<int> black_update(n), white_update(n);

    ll res = 0;
    for(int t = 1; t <= q; t++){
        int type;
        cin >> type;
        if(type == 1){
            int r;
            cin >> r;
            r--;
            int pre = black_update[r];
            if(pre == 0) res += n;
            else{
                res += col.sum(pre, t + 1);
                row.add(pre,-1);
            }
            row.add(t,1);
            black_update[r] = t;
        } else {
            int c;
            cin >> c;
            c--;
            int pre = white_update[c];
            res -= row.sum(pre,t + 1);
            if(pre != 0) col.add(pre,-1);
            col.add(t,1);
            white_update[c] = t;
        }
        cout << res << endl;
    }
    
    return 0;
}