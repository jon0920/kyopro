#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    rep(i,n){
        if((i + 1) % 3 == 0) cout << 'x';
        else cout << 'o';
    }
    cout << endl;
    
    return 0;
}