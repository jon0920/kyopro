#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int l, r;
    cin >> l >> r;
    if(l == r){
        cout << "Invalid" << endl;
        return 0;
    }
    else{
        cout << (l == 1 ? "Yes" : "No") << endl;
    }
    
    return 0;
}