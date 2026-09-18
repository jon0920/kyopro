#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int cnt = n;
    int ans = 0;
    rep(i,n){
        int f;
        cin >> f;
        cnt = max(0, cnt - f);
        if(cnt > 0){
            ans++;
            cnt--;
        }
    }

    cout << ans << endl;
    
    return 0;
}