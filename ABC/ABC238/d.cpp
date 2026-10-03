#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll a, s;
        cin >> a >> s;
        ll x = 0, y = 0;
        rep(i,61){
            if((a >> i) & 1){
                x += (1LL << i);
                y += (1LL << i);
            }
        }

        if(x + y > s){
            cout << "No" << endl;
            continue;
        }

        for(int i = 60; i >= 0; i--){
            if((x >> i) & 1) continue;

            if(x + (1LL << i) + y <= s) x += (1LL << i);
        }

        if(x + y == s) cout << "Yes" << endl;
        else cout << "No" << endl;
    }    
    
    return 0;
}