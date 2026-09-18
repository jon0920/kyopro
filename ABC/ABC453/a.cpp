#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    while(!s.empty() && s.back() == 'o') s.pop_back();
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}