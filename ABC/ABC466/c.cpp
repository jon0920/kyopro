#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;

    ll ans = 0;
    int j = 1;
    for(int i = 1; i <= n; i++){
        if(j < i) j = i;
        while(j + 1 <= n){
            cout << "? " << i << " " << j + 1 << endl;
            string res;
            cin >> res;
            if(res == "Yes") j++;
            else break;
        }
        ans += j - i;
    }

    cout << "! " << ans << endl;
    
    return 0;
}