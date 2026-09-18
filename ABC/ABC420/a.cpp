#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int x, y;
    cin >> x >> y;
    int ans = (x + y) % 12;
    if(ans == 0) ans = 12;
    cout << ans << endl;
    
    return 0;
}