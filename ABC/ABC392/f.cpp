#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return a + b; }
int e(){ return 0; }
int target;
bool f(int x){ return x < target; }

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    
    vector<int> v(n, 1);
    segtree<int, op, e> seg(v);

    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--){
        target = p[i];
        int pos = seg.max_right<f>(0);
        res[pos] = i + 1;
        seg.set(pos, 0);
    }

    for(int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}