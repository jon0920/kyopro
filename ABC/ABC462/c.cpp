#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> yx(n + 1);
    rep(i,n){
        int x, y;
        cin >> x >> y;
        yx[x] = y;
    }

    int ans = 0;
    int mn = n + 1;
    for(int x = 1; x <= n; x++){
        int crr = yx[x];
        if(crr < mn){
            ans++;
            mn = crr;
        }
    }
    cout << ans << endl;

    
    return 0;
}