#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<ll> f(10);
    cin >> f[0] >> f[1];

    for(int i = 2; i < 10; i++){
        ll x = f[i - 2] + f[i - 1];
        string s = to_string(x);
        reverse(s.begin(), s.end());
        f[i] = stoll(s);
    }
    cout << f[9] << endl;
    
    return 0;
}