#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    int ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        ans += min(m, a / 100);
    }

    cout << ans << endl;
    
    return 0;
}