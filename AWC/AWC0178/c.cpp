#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, m;
    cin >> n >> k >> m;
    vector<ll> d(k);
    rep(i,k){
        int b;
        cin >> b;
        cin >> d[i];
    }
    sort(d.rbegin(), d.rend());

    ll ans = 0;
    rep(i,k){
        if(i % m == 0) ans += d[i] * 2;
    }

    cout << ans << endl;
    
    return 0;
}