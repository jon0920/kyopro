#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> l(n), r(n);
    l[0] = 1; r[n - 1] = 1;
    for(int i = 1; i < n; i++){
        int lim = min(l[i - 1] + 1, a[i]);
        l[i] = lim;
    }
    for(int i = n - 2; i >= 0; i--){
        int lim = min(r[i + 1] + 1, a[i]);
        r[i] = lim;
    }

    int ans = 1;
    rep(i,n){
        ans = max(ans, min(l[i], r[i]));
    }

    cout << ans << endl;
    
    return 0;
}