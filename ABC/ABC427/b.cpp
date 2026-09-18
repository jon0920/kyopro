#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    int ans = 1;

    rep(i,n - 1){
        int fa = ans;
        while(fa){
            int x = fa % 10;
            ans += x;
            fa /= 10;
        }
    }
    cout << ans << endl;
    
    return 0;
}