#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    rep(i,m){
        int t;
        ll v;
        cin >> t >> v;
        t--;
        s[t] = max(0LL, s[t] + v);
    }

    for(auto x : s) cout << x << " ";
    cout << endl;
    
    return 0;
}