#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    cin >> l;
    vector<int> c(l);
    rep(i,l) cin >> c[i];
    int q;
    cin >> q;
    vector<int> x(q);
    rep(i,q) cin >> x[i];
    
    set<int> s;
    rep(i,n) rep(j,m) rep(k,l) s.insert(a[i] + b[j] + c[k]);

    rep(i,q){
        if(s.count(x[i])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}