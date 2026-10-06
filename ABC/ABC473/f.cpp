#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = int;
using F = int;

S op(S a, S b) { return min(a, b); }
S e(){ return 1e9; }
F mapping(F f, S x){ return f + x; }
F composition(F f, F g){ return f + g; }
F id(){ return 0; }

int main(){
    
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> d(n);
    rep(i,n){
        d[i] = (s[i] == 'A' ? 1 : -1);
    }
    vector<int> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + d[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(sum);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i;
            char c;
            cin >> i >> c;
            i--;
            if(s[i] != c){
                s[i] = c;
                if(c == 'A') seg.apply(i + 1, n + 1, 2);
                else seg.apply(i + 1, n + 1, -2);
            }
        } else {
            int l, r;
            cin >> l >> r;
            int v = seg.get(l - 1);
            if(seg.prod(l, r + 1) < v) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    
    return 0;
}