#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll total = 0;
    rep(i,n){
        cin >> a[i];
        total += a[i];
    }
    s %= total;

    vector<ll> sum(2 * n + 1);
    rep(i,2 * n) sum[i + 1] = sum[i] + a[i % n];

    for(auto x : sum){
        if(binary_search(sum.begin(), sum.end(), s + x)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}