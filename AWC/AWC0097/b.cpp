#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> t(n), sum(n + 1);
    rep(i,n){
        cin >> t[i];
        sum[i + 1] = sum[i] + t[i];
    }

    ll s = 0;
    rep(i,n - k + 1){
        s = max(s, sum[i + k] - sum[i]);
    }
    
    cout << s * 1000 / k << endl;
    
    return 0;
}