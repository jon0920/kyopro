#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<ll> c(n), s(n + 1);
    rep(i,n){
        cin >> x[i] >> c[i];
        s[i + 1] = s[i] + c[i];
    }

    int ans = 0;
    rep(i,n){
        int pos = upper_bound(s.begin(), s.end(), s[i] + m) - s.begin();
        ans = max(ans, x[pos - 2] - x[i]);
    }

    cout << ans << endl;
    
    return 0;
}