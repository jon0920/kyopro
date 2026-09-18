#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans = 1;
    int mx = h[0];
    for(int i = 1; i < n; i++){
        if(h[i] > mx){
            ans++;
            mx = h[i];
        }
    }
    cout << ans << endl;

    return 0;
}