#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, l, r;
    cin >> n >> l >> r;

    int ans = -1;
    int cur = 0, min_cur = 0;
    rep(i,n){
        int t;
        cin >> t;
        if(t >= l && t <= r) cur++;
        else cur--;
        ans = max(ans, cur - min_cur);
        min_cur = min(min_cur, cur);
    }

    cout << ans << endl;
    
    return 0;
}