#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return max(a, b); }
int e() { return 0; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> c(n);
    rep(i,n) c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        
    vector<tuple<int,int,int>> Q(q);
    rep(i,q){
        int r, x;
        cin >> r >> x;
        r--;
        Q[i] = {r, x, i};
    }
    sort(Q.begin(), Q.end());
    
    segtree<int, op, e> seg(n);
    int cur = 0;
    vector<int> res(q);
    for(auto [r, x, id] : Q){
        while(cur < n && cur <= r){
            int mx = seg.prod(0, c[cur]);
            if(seg.get(c[cur]) < mx + 1){
                seg.set(c[cur], mx + 1);
            }
            cur++;
        }

        int p = upper_bound(b.begin(), b.end(), x) - b.begin();

        res[id] = seg.prod(0, p);
    }

    for(int x : res) cout << x << endl;
    
    return 0;
}