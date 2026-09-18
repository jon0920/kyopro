#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(a[i] * 2 >= b[j]){
            ans++;
            i++, j++;
        } else i++;
    }

    cout << ans << endl;
    
    return 0;
}