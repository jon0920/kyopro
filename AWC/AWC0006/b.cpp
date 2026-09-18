#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k, t;
    cin >> n >> k >> t;
    ll sum = 0;
    rep(i,n){
        ll d, r;
        cin >> d >> r;
        if(r >= k * d) sum += r;
    }
    if(sum >= t) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}