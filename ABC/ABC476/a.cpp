#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    if(s.back() == 'e') s += "r";
    else s += "er";

    cout << s << endl;
    
    return 0;
}