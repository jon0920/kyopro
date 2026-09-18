#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n), s(n + 1);
    rep(i,n){
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    int mn = 1e9, mx = 0;
    rep(i,n - k + 1){
        mn = min(mn, s[i + k] - s[i]);
        mx = max(mx, s[i + k] - s[i]);
    }
    cout << mx - mn << endl;
    
    return 0;
}