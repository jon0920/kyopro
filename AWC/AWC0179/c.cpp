#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    rep(i,n){
        int b, d;
        cin >> b >> d;
        b--;
        c[b] = max(c[b], d);
    }

    ll ans = 0;
    rep(i,k) ans += c[i];
    cout << ans << endl;
    
    return 0;
}