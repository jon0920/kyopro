#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int mx = -1;
    string s;
    rep(i,n){
        int a;
        cin >> a;
        if(mx < a){
            s += "o";
            mx = a;
        } else s += "x";
    }
    cout << s << endl;
    
    return 0;
}