#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, x, y;
    cin >> n >> x >> y;
    string res;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(a >= x && b <= y) res += "G";
        else res += "B";
    }
    cout << res << endl;
    
    return 0;
}