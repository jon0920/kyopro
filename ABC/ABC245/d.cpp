#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), c(n + m + 1);
    rep(i,n + 1) cin >> a[i];
    rep(i,n + m + 1) cin >> c[i];
    
    for(int i = m; i >= 0; i--){
        b[i] = c[i + n] / a[n];
        rep(j,n + 1){
            c[i + j] -= b[i] * a[j];
        }
    }

    rep(i,m + 1) cout << b[i] << " ";
    cout << endl;
    
    return 0;
}