#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    int mx = *max_element(a.begin(), a.end());
    int ans = 0;
    rep(i,m){
        if(b[i] <= mx) ans++;
        else break;
    }
    cout << ans << endl;
    
    return 0;
}