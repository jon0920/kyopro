#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int i = 0, j = 0;
    ll ans = -1;
    while(i < n && j < m){
        if(a[i] < b[j]){
            if(b[j] - a[i] <= d){
                ans = a[i] + b[j];
                break;
            }
            j++;
        } else {
            if(a[i] - b[j] <= d){
                ans = a[i] + b[j];
                break;
            }
            i++;
        }
    }

    cout << ans << endl;
    
    return 0;
}