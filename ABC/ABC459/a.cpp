#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int x;
    cin >> x;
    x--;
    string s = "HelloWorld";

    int n = s.size();
    rep(i,n){
        if(i != x) cout << s[i];
    }

    cout << endl;
    
    return 0;
}