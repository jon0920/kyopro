#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n){
        if(a[i] <= l) cout << l << " ";
        else if(a[i] >= r) cout << r << " ";
        else cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}