#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    char c1, c2;
    string s;
    cin >> n >> c1 >> c2 >> s;
    for(auto c : s){
        if(c != c1) cout << c2;
        else cout << c1;
    }

    cout << endl;

    return 0;
}