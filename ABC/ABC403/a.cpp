#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    int ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(i % 2 == 0) ans += a;
    }
    
    cout << ans << endl;
    return 0;
}