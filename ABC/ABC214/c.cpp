#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];

    vector<ll> ans(n);
    ans[0] = t[0];
    rep(i,n * 2){
        ll time = s[i % n];
        ll last = ans[i % n];
        if(last + time < t[(i + 1) % n]){
            ans[(i + 1) % n] = last + time;
        }
        else ans[(i + 1) % n] = t[(i + 1) % n];
    }
    
    for(auto x : ans) cout << x << endl;
    return 0;
}