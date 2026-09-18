#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, l;
    cin >> n >> l;
    int crr = 0;
    int ans = -1;
    rep(i,n){
        int d;
        cin >> d;
        if(l >= d && crr < d){
            ans = i + 1;
            crr = d;
        }
    }

    cout << ans << endl;

    return 0;
}