#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, x;
    cin >> n >> x;
    int ans = -1;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        x -= a;
        if(x <= 0){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}