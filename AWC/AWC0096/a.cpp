#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll t = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        if(i == 0){
            t = a + b;
        } else {
            t = max(t, a);
            t += b;
        }
    }

    cout << t << endl;
    
    return 0;
}