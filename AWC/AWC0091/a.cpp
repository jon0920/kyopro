#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    
    int mn = 1e9, mx = 0;
    rep(i,n - 1){
        mn = min(mn, t[i + 1] - t[i]);
        mx = max(mx, t[i + 1] - t[i]);
    }

    cout << mn << " " << mx << endl;
    
    return 0;
}