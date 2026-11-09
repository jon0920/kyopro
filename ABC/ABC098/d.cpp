#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int XOR = 0, SUM = 0;
    ll r = 0;
    ll ans = 0;
    for(ll l = 0; l < n; l++){
        while(r < n){
            int nx = XOR ^ a[r];
            int ns = SUM + a[r];
            if(nx != ns) break;
            XOR = nx; SUM = ns;
            r++;
        }
        ans += r - l;
        XOR ^= a[l];
        SUM -= a[l];
    }

    cout << ans << endl;
    
    return 0;
}