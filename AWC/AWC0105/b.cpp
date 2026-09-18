#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, p;
    cin >> n >> p;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    sort(s.begin(), s.end());

    int ans = 0;
    rep(i,n){
        if(p < s[i]) break;
        p -= s[i];
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}