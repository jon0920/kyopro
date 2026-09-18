#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    if(n % 2 == 0){
        rep(i,(n - 2) / 2) cout << '-';
        cout << "==";
        rep(i,(n - 2) / 2) cout << '-';
    }
    else{
        rep(i,(n - 1) / 2) cout << '-';
        cout << "=";
        rep(i,(n - 1) / 2) cout << '-';
    }
    cout << endl;
    return 0;
}