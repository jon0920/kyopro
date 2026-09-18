#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    int j = 0;
    while(1){
        int cnt = 0;
        rep(i,n){
            if(a[i] >= j) cnt++;
        }
        if(cnt >= j) ans = j;
        else break;
        j++;
    }
    cout << ans << endl;
    return 0;
}