#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        a[i] *= n;
        sum += a[i];
    }

    ll avr = sum / n;

    int ans = -1;
    ll mx = -1;
    rep(i,n){
        if(mx < (abs(avr - a[i]))){
            ans = i + 1;
            mx = abs(avr - a[i]);
        }
    }

    cout << ans << endl;
    
    return 0;
}