#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ta = 0, ao = 0;
    rep(i,n){
        if(i % 2 == 0) ta += a[i];
        else ao += a[i];
    }

    cout << ta - ao << endl;

    return 0;
}