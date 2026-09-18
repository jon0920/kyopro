#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    if(s > t) swap(s, t);
    ll ans = 0;
    rep(i,m){
        int p, v;
        cin >> p >> v;
        if(p >= s && p <= t) ans += v;
    }
    cout << ans << endl;
    
    return 0;
}