#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    cout << x[k - 1] - 1 << endl;
    
    return 0;
}