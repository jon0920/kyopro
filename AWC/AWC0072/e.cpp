#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> s(n), p(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> p[i];
    fenwick_tree<int> fw(n);
    rep(i,n) if(s[i] < p[i]) fw.add(i, 1);

    while(m--){
        int l, r;
        cin >> l >> r;
        l--;
        if(fw.sum(l, r) > 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    
    return 0;
}