#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int s, a, b, x;
    cin >> s >> a >> b >> x;

    int ans = 0;
    for(int i = 1; i <= x; i++){
        if(i % (a + b) <= a && i % (a + b) != 0) ans += s;
    }
    cout << ans << endl;
    
    return 0;
}