#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, l, r, m;
    cin >> n >> l >> r >> m;
    int ans = 0;
    rep(i,n){
        int p, k;
        cin >> p >> k;
        if(l <= p && p <= r && k <= m) ans++;
    }

    cout << ans << endl;
    
    return 0;
}