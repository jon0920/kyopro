#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans(n);
    for(int i = 1; i < n; i++){
        if(a[i - 1] > a[i]){
            ans[i] = i;
        } else {
            ans[i] = 0;
        }
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}