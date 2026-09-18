#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int e = 0, w = 0;
    int n = s.size();
    rep(i,n){
        if(s[i] == 'E') e++;
        else w++;
    }

    if(e < w) cout << "West" << endl;
    else cout << "East" << endl;

    
    return 0;
}