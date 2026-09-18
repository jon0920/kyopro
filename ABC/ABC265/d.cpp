#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n), s(n + 1);
    rep(i,n){
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    auto check = [&](ll x){
        return (binary_search(s.begin(), s.end(), x));
    };
    
    for(auto x : s){
        if(check(x + p) && check(x + p + q) && check(x + p + q + r)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}