#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    int ans = 0;
    rep(i,n){
        int sum = 0;
        rep(j,d){
            int a;
            cin >> a;
            sum += abs(a - t[i]);
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}