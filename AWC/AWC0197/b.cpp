#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    int ans = -1;
    rep(i,n){
        int a;
        cin >> a;
        if(a >= k) ans = i + 1;
    }
    cout << ans << endl;
    
    return 0;
}