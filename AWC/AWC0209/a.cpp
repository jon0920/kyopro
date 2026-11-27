#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int k;
    string s;
    cin >> k >> s;
    string ans;
    for(char c : s){
        int x = c - 'A';
        x = (x + k) % 26;
        ans += (char)x + 'A';
    }

    cout << ans << endl;
    
    return 0;
}