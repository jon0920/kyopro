#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int op1(int a, int b){
    return max(a, b);
}
int op2(int a, int b){
    return min(a, b);
}

int e1(){
    return -INF;
}
int e2(){
    return INF;
}

int main(){

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    segtree<int, op1, e1> seg1(a);
    segtree<int, op2, e2> seg2(a);

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        ll mx = seg1.prod(l, r);
        ll mn = seg2.prod(l, r);

        cout << mx - mn << endl;
    }

    return 0;
}