#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        int n;
        cin >> n;
        int ans = 0;
        rep(i,n){
            int a;
            cin >> a;
            if(a % 2 == 1) ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}