#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, p, b, k;
    cin >> n >> p >> b >> k;
    int ans = 0;
    rep(i,n){
        int c;
        cin >> c;
        if(c >= k) ans += (p + b) * c;
        else ans += p * c;
    }

    cout << ans << endl;

    return 0;
}