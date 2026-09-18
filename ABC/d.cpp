#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll M = 1'000'000;

int main(){
    
    ll n, m;
    cin >> n >> m;
    if(n < M && n * n < m){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 1e18;
    for(ll a = 1; a <= M; a++){
        ll b = (m + a - 1) / a;
        if(a <= n && b <= n) ans = min(ans, a * b);
    }
    cout << ans << endl;
    
    return 0;
}