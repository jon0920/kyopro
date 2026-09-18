#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    int ans = -1;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int leader = a[0];
    for(int i = 1; i < n; i++){
        if(leader < a[i]){
            ans = i + 1;
            leader = a[i];
        }
    }

    cout << ans << endl;

    return 0;
}