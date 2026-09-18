#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m; ll s;
    cin >> n >> m >> s;
    ll A = 0, B = 0;
    rep(i,n){
        ll a;
        cin >> a;
        A += a;
    }
    rep(i,m){
        ll b;
        cin >> b;
        B += b;
    }

    if(A - B >= 0) cout << -1 << endl;
    else cout << s / -(A - B) << endl;
    
    return 0;
}