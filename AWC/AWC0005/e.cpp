#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){
    return max(a, b);
}
int e(){
    return -1;
}

int main(){

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    segtree<int, op, e> seg(a);

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << seg.prod(l, r) << endl;
    }
 
    return 0;
}