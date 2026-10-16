#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int mx = 10000;
    int ans = -1;
    rep(i,n){
        int a;
        cin >> a;
        if(mx > a){
            ans = i + 1;
            mx = a;
        }
    }
    cout << ans << endl;
    
    return 0;
}