#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, x;
    cin >> n >> x;
    string res = "";
    rep(i,n){
        int a;
        cin >> a;
        if(x >= a) res += "o";
        else res += "x";
    }
    cout << res << endl;
    
    return 0;
}