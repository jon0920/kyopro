#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    ll d = 0;
    for(int i = n - 1; i >= 1; i--){
        d = max(d, a[i]);
        a[p[i]] += a[i];
    }

    cout << sum - d << endl;
    
    return 0;
}