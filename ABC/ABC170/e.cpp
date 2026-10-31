#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 2e5 + 10;
const int INF = 1e9;

int op(int a, int b){ return min(a, b); }
int e(){ return INF; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    vector<multiset<int>> cand(M);
    rep(i,n){
        cin >> a[i] >> b[i];
        cand[b[i]].insert(a[i]);
    }

    segtree<int, op, e> seg(M);
    rep(i,M){
        if(cand[i].empty()) seg.set(i, INF);
        else seg.set(i, *cand[i].rbegin());
    }

    while(q--){
        int c, d;
        cin >> c >> d;
        c--;
        int x = a[c], y = b[c];
        cand[y].erase(cand[y].find(x));
        if(cand[y].empty()) seg.set(y, INF);
        else seg.set(y, *cand[y].rbegin());

        cand[d].insert(x);
        seg.set(d, *cand[d].rbegin());

        cout << seg.all_prod() << endl;
    }
    
    return 0;
}