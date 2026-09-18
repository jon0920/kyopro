#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(-100);

    int ans = 0, cnt = 0;
    for(auto x : a){
        if(x >= k) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    cout << ans << endl;
    
    return 0;
}