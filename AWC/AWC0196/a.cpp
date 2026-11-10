#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    bool x = false, y = false;
    for(char c : s){
        if(c == 'C') x = true;
        if(c == 'B') y = true;
    }

    if(x && y) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}