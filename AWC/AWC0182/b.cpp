#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    bool ok = true;
    rep(i,n){
        int a;
        cin >> a;
        if(a == 0) ok = false;

        if(ok && a == 1) cout << 'o';
        else cout << 'x';
    }
    cout << endl;
    
    return 0;
}