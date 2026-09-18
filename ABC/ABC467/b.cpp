#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int x = 10000, y = 10000;
    rep(i,n){
        int a, b;
        string s;
        cin >> a >> b >> s;
        if(s == "take"){
            x -= a;
        } else {
            x -= b;
        }
        y -= a;
    }

    cout << y - x << endl;
    
    return 0;
}