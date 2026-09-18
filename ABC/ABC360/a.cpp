#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    bool flag = false;
    rep(i,3){
        char c;
        cin >> c;
        if(c =='M') flag = true;
        if(c == 'R' && !flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}