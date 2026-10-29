#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0;
    int mx = 0;
    rep(i,n - 1){
        if(a[i + 1] - a[i] > mx){
            ans = i + 1;
            mx = a[i + 1] - a[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}