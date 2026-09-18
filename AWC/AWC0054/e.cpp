#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return a + b; }
int e() { return 0; }

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> vec(n, 1);
    segtree<int, op, e> seg(vec);
    
    rep(i,m){
        int s;
        cin >> s;
        cout << seg.prod(0, s) << endl;
        seg.set(s - 1, 0);
    }

    return 0;
}