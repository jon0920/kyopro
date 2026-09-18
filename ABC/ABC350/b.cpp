#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    vector<bool> check(n, true);
    
    rep(i,q){
        int t;
        cin >> t;
        t--;
        if(check[t]) check[t] = false;
        else check[t] = true;
    }
    int ans = 0;
    rep(i,n){
        if(check[i]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}