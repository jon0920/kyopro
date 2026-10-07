#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int op(int a, int b){ return min(a, b); }
int e(){ return INF; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> cnt(n);
    vector<int> h;
    for(int i = n - 1; i >= 0; i--){
        while(!h.empty() && h.back() <= a[i]) h.pop_back();
        h.push_back(a[i]);
        cnt[i] = h.size();
    }

    segtree<int, op, e> seg(cnt);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << cnt[l] - seg.prod(l, r) + 1 << endl;
    }
    
    return 0;
}