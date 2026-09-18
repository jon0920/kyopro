#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<ll> ans;
    for(int bit = 2; bit < (1 << 10); bit++){
        ll x = 0;
        for(int j = 9; j >= 0; j--){
            if(bit & (1 << j)){
                x *= 10;
                x += j;
            }
        }
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());

    int k;
    cin >> k;
    cout << ans[k - 1] << endl;
    
    return 0;
}