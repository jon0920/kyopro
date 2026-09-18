#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;

    cout << (ll)sqrtl(n / 2) + (ll)sqrtl(n / 4) << endl;
    
    return 0;
}