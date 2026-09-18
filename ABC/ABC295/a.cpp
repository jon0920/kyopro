#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    bool ans = false;
    rep(i,n){
        string w;
        cin >> w;
        if(w == "and" || w == "not" || w == "that" || w == "the" || w == "you") ans = true;
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}