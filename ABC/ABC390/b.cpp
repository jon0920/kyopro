#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> a(100);
    rep(i,n) cin >> a[i];

    bool ok = true;
    for(int i = 1; i < n-1; i++){
        if(a[i] * a[i] != a[i-1] * a[i+1]) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}