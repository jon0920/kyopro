#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return a + b; }
int e(){ return 0; }

int main(){
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> diff(n - 1);
    rep(i,n - 1) diff[i] = (s[i] == s[i + 1]);

    segtree<int, op, e> seg(diff);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            l--, r--;
            if(l > 0){
                seg.set(l - 1, seg.get(l - 1) ^ 1);
            }
            if(r < n - 1){
                seg.set(r, seg.get(r) ^ 1);
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            if(seg.prod(l, r) > 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    
    return 0;
}