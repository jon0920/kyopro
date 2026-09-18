#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    bool ok = false;
    rep(i,n){
        int x;
        cin >> x;
        if(x >= 0) ok = true;
    }

    cout << (ok ? "No" : "Yes") << endl; 
    
    return 0;
}