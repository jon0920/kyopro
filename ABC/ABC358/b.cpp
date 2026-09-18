#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    rep(i,n) cin >> t[i];

    int cnt = 0;
    rep(i,n){
        if(i == 0){
            cout << t[i] + a << endl;
            cnt += t[i] + a;
            continue;
        }
        if(cnt >= t[i]){
            cout << cnt + a << endl;
            cnt += a;
        }
        else{
            cout << t[i] + a << endl;
            cnt = t[i] + a;
        }
    }
    
    return 0;
}