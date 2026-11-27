#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    int ans = -1;
    int mn = 1000;
    rep(i,h){
        string s;
        cin >> s;
        int sum = 0;
        for(char c : s){
            sum += c - '0';
        }
        if(mn > sum){
            mn = sum;
            ans = i + 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}