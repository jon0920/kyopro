#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, x;
    cin >> n >> x;
    int ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        ans += max(0, a - x);
    }

    cout << ans << endl;

    return 0;
}