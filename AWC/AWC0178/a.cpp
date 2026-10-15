#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    string res = "";
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(a > b) res += "H";
        else if(a < b) res += "L";
        else res += "E";
    }

    cout << res << endl;
    
    return 0;
}