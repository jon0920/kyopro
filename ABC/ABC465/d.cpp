#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll x, y, k;
        cin >> x >> y >> k;
        if(x == y){
            cout << 0 << endl;
            continue;
        }

        if(x < y) swap(x,y);
        int ans = 1;
        while((x / k) != y){
            ans++;
            x /= k;
            if(x < y) swap(x,y);
        }

        cout << ans  << endl;
    }
    
    return 0;
}