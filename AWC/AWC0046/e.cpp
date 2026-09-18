#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int offset = 50000;
const int INF = 1e9;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> D(n);
    rep(i,n) cin >> D[i];
    int mx = INF, mn = -INF;

    bool movable = true;
    rep(i,m){
        int x;
        cin >> x;
        if(x == 0) movable = false;
        if(x > 0) mx = min(mx, x);
        if(x < 0) mn = max(mn, x);
    }
    if(!movable){
        cout << 0 << endl;
        return 0;
    }
    mx = min(mx - 1, offset);
    mn = max(mn + 1, -offset);
    
    bitset<100001> dp, mask;
    dp[offset] = 1;
    rep(i,100001){
        int p = i - offset;
        if(mn <= p && mx >= p) mask[i] = 1;
    }
    
    for(int d : D){
        if(d > 0){
            dp |= (dp << d);
        } else {
            dp |= (dp >> -d);
        }
        dp &= mask;
    }

    for(int i = 100000; i >= 0; i--){
        if(dp[i]){
            cout << i - offset << endl;
            return 0;
        }
    }

    return 0;
}