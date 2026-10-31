#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int cnt = 0;
    for(char c : s) if(c == 'o') cnt++;

    cout << (cnt % 2 == 1 ? "odd" : "even") << endl;
    
    return 0;
}