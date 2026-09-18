#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;

    bool ok = true;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        if(p > ((i + 9) / 10) * 10) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}