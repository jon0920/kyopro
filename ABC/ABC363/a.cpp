#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int r;
    cin >> r;
    r = r % 100;
    int ans = 100 - r;
    cout << ans << endl;
    
    return 0;
}