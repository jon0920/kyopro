#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return max(a, b); }
int e(){ return 0; }

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    auto LIS = [&](vector<int> v){
        int sz = v.size();
        vector<pair<int,int>> sort_v(sz);
        rep(i,sz){
            sort_v[i] = {v[i], i};
        }

        sort(sort_v.begin(), sort_v.end());
        /*
        狭義増加列
        sort(sort_v.begin(), sort_v.end(), [](const auto &x, const auto &y){
            if(x.first != y.first) return x.first < y.first;
            return x.second > y.second;
        });
        */

        segtree<int, op, e> seg(sz);
        for(auto [x, i] : sort_v){
            int mx = seg.prod(0, i);
            seg.set(i, mx + 1);
        }

        return seg.all_prod();
    };

    cout << n - LIS(a) << endl;
    
    return 0;
}