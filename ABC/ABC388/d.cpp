#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
//imos法 ++, --と累積を同時に

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> c(n), imos(n + 1);
    rep(i,n){
        if(i != 0){
            c[i] = c[i - 1] + imos[i];
            a[i] += c[i];
        }
        int cnt = min(n - i - 1, a[i]);
        a[i] -= cnt;
        imos[i + 1]++;
        imos[min(n, i + cnt + 1)]--;
    }
    for(auto x : a) cout << x << " ";
    cout << endl;
    
    return 0;
}