#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> l(n);
    int sum = 0;
    rep(i,n){
        cin >> l[i];
        sum += l[i];
    }
    int ans = 1e9;
    int cur = 0;
    rep(i,n){
        cur += l[i];
        sum -= l[i];
        ans = min(ans, abs(cur - sum));
    }

    cout << ans << endl;
    
    return 0;
}