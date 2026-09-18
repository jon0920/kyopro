#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int l, n, c;
    cin >> l >> n >> c;
    vector<int> p(n), w(n);
    rep(i,n) cin >> p[i] >> w[i];
    bool ok = true;
    int crr = c;
    int last = 0;
    rep(i,n){
        crr -= p[i] - last;
        if(crr < 0) ok = false;
        crr = min(c, crr + w[i]);
        last = p[i];
    }

    crr -= l - last;
    if(crr < 0) ok = false;

    cout << (ok ? crr : -1) << endl;
    
    return 0;
}