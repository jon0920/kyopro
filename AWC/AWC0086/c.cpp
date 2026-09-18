#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    rep(i,m) cin >> b[i];

    vector<int> op;
    rep(qi,q){
        int l, r;
        cin >> l >> r;
        op.push_back(l);
        op.push_back(r + 1);
    }
    sort(op.begin(), op.end());

    int ans = 0;
    for(auto x : b){
        int cnt = upper_bound(op.begin(), op.end(), x) - op.begin();
        if(cnt % 2 == 1) ans++;
    }
    cout << ans << endl;
    
    return 0;
}