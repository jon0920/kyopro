#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    int ans = 0;
    rep(i,n){
        if(binary_search(sum.begin(), sum.end(), k + sum[i])) ans++;
    }
    cout << ans << endl;
    
    return 0;
}