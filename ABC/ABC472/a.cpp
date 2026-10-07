#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    for(char c : s){
        if(c != 'A') cout << '.';
        else cout << c;
    }
    cout << endl;
    
    return 0;
}