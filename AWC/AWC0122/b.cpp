#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] > d) ans += a[i] - a[i - 1];
    }

    cout << ans << endl;
    
    return 0;
}