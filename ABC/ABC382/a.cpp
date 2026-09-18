#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int emp = 0, cnt = 0;
    for(auto c : s){
        if(c == '.') emp++;
        else cnt++;
    }

    cout << emp + min(d, cnt) << endl;

    return 0;
}