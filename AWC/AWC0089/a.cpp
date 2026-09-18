#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    while(q--){
        int d;
        cin >> d; d--;
        sum -= a[d];
        cout << sum << endl;
    }

    
    return 0;
}