#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, b;
    cin >> n >> b;
    vector<ll> p(n), c(n - 1);
    rep(i,n) cin >> p[i];
    rep(i,n - 1) cin >> c[i];

    vector<ll> sum_p(n + 1);
    rep(i,n) sum_p[i + 1] = sum_p[i] + p[i];

    ll ans = 0;
    ll sum_c = 0;
    int r = 0;
    for(int l = 0; l < n - 1; l++){
        while(r < n - 1 && sum_c + c[r] <= b){
            sum_c += c[r];
            r++;
        }
        ans = max(ans, sum_p[r + 1] - sum_p[l]);
        sum_c -= c[l];
    }

    cout << ans << endl;
    
    return 0;
}