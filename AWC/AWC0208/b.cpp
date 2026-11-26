#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, x;
    cin >> n >> x;
    rep(i,n){
        char t; int a;
        cin >> t >> a;
        if(t == 'D'){
            x += a;
        } else {
            if(x >= a) x -= a;
        }
        cout << x << endl;
    }
    
    return 0;
}