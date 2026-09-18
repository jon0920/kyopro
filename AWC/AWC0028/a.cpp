#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    int ans = 0;
    rep(i,n){
        int p;
        cin >> p;
        if(p >= k) ans += p;
    }
    cout << ans << endl;

    return 0;
}