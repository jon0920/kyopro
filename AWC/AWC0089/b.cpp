#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        int b;
        cin >> b;
        if(b == 1) a[i] = max(0LL, a[i] - c);
    }
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    ll sum = 0;
    rep(i,n){
        if(i) sum -= k;
        sum += a[i];
        ans = max(ans, sum);
    }

    cout << (ans >= d ? ans : -1) << endl;
    
    return 0;
}