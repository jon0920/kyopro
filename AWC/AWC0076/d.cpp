#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, q;
    cin >> n >> k >> q;
    vector<array<int, 5>> vec;
    rep(i,n){
        int d;
        cin >> d;
        vec.push_back({d, 1, i, 0, 0});
    }
    rep(i,q){
        int l, r, t;
        cin >> l >> r >> t;
        vec.push_back({t, 2, l-1, r, i});
    }
    sort(vec.begin(), vec.end());

    atcoder::fenwick_tree<int> fw(n);
    vector<int> ans(q);
    for(auto [d, e, l, r, i] : vec){
        if(e == 1){
            fw.add(l, 1);
        } else {
            if(fw.sum(l, r) > k) ans[i] = -1;
            else ans[i] = fw.sum(l, r);
        }
    }

    rep(i,q) cout << ans[i] << endl;
    
    return 0;
}