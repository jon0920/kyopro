#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, l, r;
    cin >> n >> l >> r;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(i < l || i > r) cout << i << " ";
        else{
            cout << r - cnt << " ";
            cnt++;
        }
    }
    cout << endl;
    
    return 0;
}