#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n - 1){
        while(a[i] > 1){
            ll x = a[i] / 2;
            a[i + 1] += x;
            a[i] -= x;
        }
    }

    cout << a[n - 1] << endl;
    
    return 0;
}