#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, w;
    cin >> n >> w;
    int ans = 0;
    int crr = 0;
    rep(i,n){
        int l;
        cin >> l;
        if(crr == 0){
            crr += l;
            ans++;
        } else {
            if(crr + l + 1 <= w) crr += l + 1;
            else{
                ans++;
                crr = l;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}