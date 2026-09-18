#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, K;
    cin >> n >> K;
    ll sum = 0;
    map<ll,ll> mp;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
        sum += b;
    }

    if(sum <= K){
        cout << 1 << endl;
        return 0;
    }
    
    for(auto [k, v] : mp){
        sum -= v;
        if(sum <= K){
            cout << k + 1 << endl;
            return 0;
        }
    }

    
    return 0;
}