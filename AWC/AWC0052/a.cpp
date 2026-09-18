#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    int pre = -1000;
    int ans = 0;
    int cnt = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(pre < a) cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 1;
        }
        pre = a;
    }
    ans = max(ans, cnt);

    cout << ans << endl;

    return 0;
}