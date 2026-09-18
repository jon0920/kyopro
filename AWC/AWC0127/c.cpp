#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int cur = 0;
    int cnt = 0;
    ll sum = 0;
    while(cur < n){
        if(sum + a[cur] <= k){
            sum += a[cur];
            cur++;
        } else {
            sum = 0;
            cnt++;
            if(cnt == m) break;
        }
    }

    cout << (cur == n ? "No" : "Yes") << endl;
    
    return 0;
}