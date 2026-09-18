#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a;
    cin >> a;
    if(400 % a != 0) cout << -1 << endl;
    else cout << 400 / a << endl;
    
    return 0;
}