#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int mx = 0, ans = -1;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        if(mx < a + b){
            mx = a + b;
            ans = i;
        }
    }
    cout << ans << endl;
    
    return 0;
}