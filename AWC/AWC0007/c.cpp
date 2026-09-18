#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    int mx = 0, ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(mx < a){
            mx = a;
            ans = i + 1;
        }
    }
    cout << ans << endl;


    return 0;
}