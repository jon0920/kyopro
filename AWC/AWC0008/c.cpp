#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> a(n), sum(n + 1);
    rep(i,n){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    int ans = 0;
    for(int i = 0; i < n - k + 1; i++){
        if(sum[i + k] - sum[i] <= 0) ans++;
    }
    cout << ans << endl;

    return 0;
}