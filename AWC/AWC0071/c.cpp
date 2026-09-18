#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,n) cin >> w[i];

    unordered_set<ll> s({0});
    ll sum = 0;
    rep(i,n){
        sum += w[i];
        s.insert(sum);
    }

    for(int k = n; k >= 1; k--){
        if(sum % k == 0){
            bool ok = true;
            rep(i,k){
                if(!s.count(sum / k * i)) ok = false;
            }
            if(ok){
                cout << k << endl;
                return 0;
            }
        }
    }
    
    return 0;
}