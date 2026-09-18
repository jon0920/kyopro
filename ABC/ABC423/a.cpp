#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int x, c;
    cin >> x >> c;

    int ans = 0;
    while(ans * (1000 + c) <= x) ans++;
    cout << (ans - 1) * 1000 << endl;
    
    return 0;
}