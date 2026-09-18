#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll sx, sy;
    ll tx, ty;
    cin >> sx >> sy >> tx >> ty;
    ll ans = abs(sy - ty);

    if(sx > tx){
        if(sy % 2 == 0 && sx % 2 == 1) sx--;
        if(sy % 2 == 1 && sx % 2 == 0) sx--;
        if(ty % 2 == 1 && tx % 2 == 0) tx++;
        if(ty % 2 == 0 && tx % 2 == 1) tx++;
    }
    if(sx < tx){
        if(sy % 2 == 1 && sx % 2 == 0) sx++;
        if(sy % 2 == 0 && sx % 2 == 1) sx++;
        if(ty % 2 == 0 && tx % 2 == 1) tx--;
        if(ty % 2 == 1 && tx % 2 == 0) tx--;  
    }

    if(abs(sy - ty) >= abs(sx - tx)) cout << ans << endl;
    else {
        ans += (abs(sy - ty) - abs(sx - tx)) % 2 + 1;
        cout << ans << endl;
    }
    
    return 0;
}