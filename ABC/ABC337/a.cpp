#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int a = 0, b = 0;
    rep(i,n){
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
    }

    if(a == b) cout << "Draw" << endl;
    else if(a > b) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    
    return 0;
}