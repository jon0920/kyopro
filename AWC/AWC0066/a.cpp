#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    while(q--){
        int b;
        cin >> b;
        b--;
        if(b == n - 1){
            a[b] = 0;
        } else {
            a[b + 1] += a[b];
            a[b] = 0;
        }
    }

    for(auto x : a) cout << x << " ";
    cout << endl;

    return 0;
}