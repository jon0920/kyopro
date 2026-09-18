#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    ll t = 0, a = 0;
    rep(i,n){
        ll x;
        cin >> x;
        if(t + x <= k) t += x;
        else a += x;
    }
    
    if(t > a) cout << "Takahashi" << endl;
    else if(t < a) cout << "Aoki" << endl;
    else cout << "Draw" << endl;

    return 0;
}