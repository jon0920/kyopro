#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    rep(i,n){
        int m;
        cin >> m;
        int cnt = 0;
        rep(j,m){
            int s;
            cin >> s;
            if(s >= k) cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}