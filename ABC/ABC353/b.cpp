#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int cnt = 0;
    int ans = 0;
    rep(i,n){
        cnt += a[i];
        if(cnt > k){
            ans++;
            cnt = a[i];
        }
        if(i == n - 1) ans++;
    }
    cout << ans << endl;
    
    return 0;
}