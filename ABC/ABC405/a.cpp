#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int r, x;
    cin >> r >> x;
    bool flag = 0;
    if(x == 1){
        if(r >= 1600 && r <= 2999) flag = 1;
    }
    if(x == 2){
        if(r >= 1200 && r <= 2399) flag = 1;
    }

    cout << (flag ? "Yes" : "No") << endl;
    
    return 0;
}