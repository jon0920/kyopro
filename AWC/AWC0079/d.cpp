#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(m);
    ll sum = 0;
    rep(i,m){
        cin >> c[i];
        sum += min(c[i], n);
    }

    if(sum >= n * k) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}