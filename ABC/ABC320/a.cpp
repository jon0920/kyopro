#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a, b;
    cin >> a >> b;
    ll A = 1, B = 1;
    rep(i,a) A *= b;
    rep(i,b) B *= a;
    cout << A + B << endl;
    
    return 0;
}