#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n){
        int x;
        cin >> x;
        a[i] = x;
        b[i] = x;
    }
    sort(b.begin(), b.end());
    vector<ll> sum(n, 0);
    rep(i,n){
        if(i == 0) sum[i] += b[i];
        else sum[i] += b[i] + sum[i - 1];
    }
    rep(i,n){
        int crr = a[i];
        int it = upper_bound(b.begin(), b.end(), crr) - b.begin();
        ll ans = sum[n - 1] - sum[it - 1];
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}