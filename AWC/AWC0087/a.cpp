#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll t, x, y;
    cin >> t >> x >> y;
    string a, b;
    cin >> a >> b;

    int ans = 0;
    rep(i,t){
        {
            if(a[i] == 'L') x--;
            else if(a[i] == 'R') x++;
        }
        {
            if(b[i] == 'L') y--;
            else if(b[i] == 'R') y++;
        }

        if(x == y) ans++;
    }

    cout << ans << endl;
    
    return 0;
}