#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int mx = 200'000;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(mx + 1);
    rep(i,n) sum[a[i]]++;
    rep(i,mx) sum[i + 1] += sum[i];

    ll ans = 0;
    rep(j,n){
        ans += sum[a[j] - 1] * (n - sum[a[j]]);
    }
    cout << ans << endl;
    
    return 0;
}