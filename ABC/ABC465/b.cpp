#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    int ans = 0;
    for(int i = a; i < b; i++){
        if(i >= l && i < r) ans += x;
        else ans += y;
    }

    cout << ans << endl;
    
    return 0;
}