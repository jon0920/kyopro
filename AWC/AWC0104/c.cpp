#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(), a.end());
    
    rep(i,m){
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if(it != a.begin() && it != a.end()){
            cout << -1 << endl;
            return 0;
        }
    }

    int mid = n / 2;
    ll ans = 0;
    rep(i,n){
        ans += abs(a[mid] - a[i]);
    }

    cout << ans << endl;

    return 0;
}