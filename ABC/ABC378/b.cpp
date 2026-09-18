#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> q(n), r(n);
    rep(i,n) cin >> q[i] >> r[i];
    int Q;
    cin >> Q;
    vector<int> t(Q), d(Q);
    rep(i,Q) cin >> t[i] >> d[i];

    rep(i,Q){
        int mod = d[i] % q[t[i] - 1];
        int dist = r[t[i] - 1] - mod;
        if(dist < 0) dist = q[t[i] - 1] + dist;
        int ans = d[i] + dist;
        cout << ans << endl;
    }
    
    return 0;
}